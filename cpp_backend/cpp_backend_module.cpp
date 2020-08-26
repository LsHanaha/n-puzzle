#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "n_puzzle.hpp"

static char	*call_backend(int side_len, int *map_array, int *goal_array, char *euristic)
{
	std::string	euristic_name(euristic);
	int (*euristic_fun)(const Puzzle*, const puzzle_config_t&);
	if (euristic_name == "hemming")
		euristic_fun = hemming;
	else if (euristic_name == "manhattan")
		euristic_fun = manhattan;
	else if (euristic_name == "phased_manhattan")
		euristic_fun = phased_manhattan;
	else if (euristic_name == "rowwise_manhattan")
		euristic_fun = rowwise_manhattan;
	else if (euristic_name == "uniform")
		euristic_fun = uniform;
	else if (euristic_name == "greedy_manhattan")
		euristic_fun = greedy_manhattan;
	else
		throw std::invalid_argument("Unknown euristic");

	Puzzle::set_side_len(side_len);
	puzzle_config_t	map(map_array, map_array + side_len * side_len);
	puzzle_config_t goal(goal_array, goal_array + side_len * side_len);
	Puzzle	*config = new Puzzle(map);
	return strdup(a_star(config, goal, euristic_fun).c_str());
}

extern "C"
{
/*===========================================================================*/

static PyObject *solve(PyObject *self, PyObject *args)
{
	int			side_len;
    PyObject	*py_map;
	PyObject	*py_goal;
	char		*euristic;

    if (!PyArg_ParseTuple(args, "iOOs", &side_len, &py_map, &py_goal, &euristic))
        return (NULL);

	int map_len = PyObject_Length(py_map);
	int *cpp_map = (int *)malloc(sizeof(int) * map_len);
	int *goal_map = (int *)malloc(sizeof(int) * map_len);
	if (!cpp_map || !goal_map)
		return (PyErr_Format(PyExc_MemoryError, "Out of memory, get more RAM!"));
	for (int i = 0; i < map_len; ++i)
	{
		cpp_map[i] = PyLong_AsLong(PyList_GetItem(py_map, i));
		goal_map[i] = PyLong_AsLong(PyList_GetItem(py_goal, i));
	}

	char		*cpp_out = call_backend(side_len, cpp_map, goal_map, euristic);
	PyObject	*py_out = Py_BuildValue("s", cpp_out, euristic);
	free(cpp_map);
	free(goal_map);
	free(cpp_out);
	return py_out;
}

static PyMethodDef Methods[] = {
    {"solve", solve, METH_VARARGS, "Solves the puzzle; expects a valid configuration"},
    {NULL, NULL, 0, NULL}  /* Sentinel */
};

static struct PyModuleDef cpp_backend_module = {
    PyModuleDef_HEAD_INIT,
    "cpp_backend",  /* name of module */
    NULL,   		/* module documentation, may be NULL */
    -1,    			/* size of per-interpreter state of the module,
               		or -1 if the module keeps state in global variables. */
    Methods
};

PyMODINIT_FUNC
PyInit_cpp_backend(void)
{
    return PyModule_Create(&cpp_backend_module);
}

/*===========================================================================*/
}

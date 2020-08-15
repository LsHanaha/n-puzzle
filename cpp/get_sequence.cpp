#include "n_puzzle.hpp"

static int
find_empty_tile(Puzzle *state)
{
    int	size = state->map.size();
    if (size == 0)
        throw std::runtime_error("A state cannot have an empty map");
    for (int i = 0; i < size; ++i)
        if (state->map[i] == size - 1)
            return i;
    throw std::runtime_error("Could not find the empty tile");
}

static void
fill_direction_string(std::string &s, Puzzle *state, Puzzle *prev_state)
{
    if (prev_state == nullptr)
        return;
    fill_direction_string(s, prev_state, prev_state->parent);
    int zero_id = find_empty_tile(state);
    int prev_zero_id = find_empty_tile(prev_state);
    char direction;
    if (zero_id > prev_zero_id)
    {
        if (zero_id / Puzzle::side_len == prev_zero_id / Puzzle::side_len)
            direction = 'r';
        else
            direction = 'd';
    }
    else
    {
        if (zero_id / Puzzle::side_len == prev_zero_id / Puzzle::side_len)
            direction = 'l';
        else
            direction = 'u';
    }
    s.push_back(direction);
}

std::string get_sequence(Puzzle *solution)
{
    std::string out;
    fill_direction_string(out, solution, solution->parent);
    return out;
}

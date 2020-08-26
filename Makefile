FILELIST = .cpp_backend_setup.txt

all:
	python setup.py build install --record $(FILELIST)

clean:
	python setup.py clean --all

fclean: clean
	xargs rm -rf < $(FILELIST)
	rm $(FILELIST)

FILELIST = .cpp_backend_setup.txt

all:
	python3 setup.py build install --record $(FILELIST)
	python3 -m pip install -U pygame==2.0.0.dev6 --user

clean:
	python3 setup.py clean --all

fclean: clean
	xargs rm -rf < $(FILELIST)
	rm $(FILELIST)
	python3 -m pip uninstall pygame -y

re: fclean all

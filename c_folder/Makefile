SRCS = a_star.c hemming.c manhattan.c

all: lib
	gcc $(SRCS) main.c -g -I ../libft/includes -L ../libft -lft
	gcc $(SRCS) unit_tests.c -g -I ../libft/includes -L ../libft -lft -o test

lib:
	make -C ../libft
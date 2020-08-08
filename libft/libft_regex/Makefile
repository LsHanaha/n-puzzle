# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/23 15:44:18 by jrobin-h          #+#    #+#              #
#    Updated: 2019/10/23 15:44:19 by jrobin-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_regex.index

CC = gcc
CFGLAGS = -Wall -Werror -Wextra -O3

SRCS = fa_state_new.c \
	ft_regex_compile.c \
	ft_regex_del.c \
	ft_regex_match.c \
	ft_regex_pmatch.c \
	ft_regex_search.c \
	regex_comparisons.c \
	regex_compile_checkers.c \
	regex_compile_fillers.c

OBJS = $(SRCS:.c=.o)

HEADS = ../includes/libft.h ../includes/regex.h \
	./includes/regex_internal.h

all: $(NAME)

$(NAME): $(OBJS)
	echo $(OBJS) > $(NAME)

$(OBJS): %.o : %.c $(HEADS)
	$(CC) $(CFLAGS) -c -I./includes -I../includes $<

clean:
	rm -f $(OBJS) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/04 14:56:41 by jrobin-h          #+#    #+#              #
#    Updated: 2018/12/19 16:23:10 by jrobin-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FUNCS =	$(shell cat ./includes/libft.h | grep -Eo "ft_\w+")
SRCS = $(FUNCS:=.c)
OBJS = $(SRCS:.c=.o)
INCLUDES = ./includes/
HEADS = libft.h

REGEX_LIB = libft_regex.index
REGEX_LIB_DIR = libft_regex/

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: submodules $(NAME)

submodules:
	make -C $(REGEX_LIB_DIR)

$(NAME): $(OBJS) $(REGEX_LIB_DIR)/$(REGEX_LIB)
	ar rc $(NAME) $(OBJS) \
		$(addprefix $(REGEX_LIB_DIR), $(shell cat $(REGEX_LIB_DIR)/$(REGEX_LIB)))
	ranlib $(NAME)

$(OBJS): %.o : %.c $(addprefix $(INCLUDES), $(HEADS))
	$(CC) $(CFLAGS) -c -I $(INCLUDES) $<

clean:
	rm -f $(OBJS)
	make -C $(REGEX_LIB_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

obj: $(OBJS)

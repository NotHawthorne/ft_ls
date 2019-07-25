# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alkozma <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/13 18:06:36 by alkozma           #+#    #+#              #
#    Updated: 2019/07/06 14:54:14 by alkozma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS = main.c \
	   print.c \
	   sort.c \
	   compare.c \
	   pad.c \
	   helper.c

OBJECTS = $(patsubst %.c,%.o,$(SRCS))

HEADERS = ft_ls.h \
		  includes/ftgnl.h \
		  includes/ft_printf.h \
		  includes/libft.h

FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME):
	make -C libft
	cp libft/libft.a ./
	gcc $(SRCS) libft.a -I includes $(FLAGS) -o $(NAME)

clean:
	make -C libft clean
	rm -rf $(OBJECTS)

fclean: clean
	make -C libft fclean
	rm -rf $(NAME) libft.a

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adubedat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/07 18:29:44 by adubedat          #+#    #+#              #
#    Updated: 2016/03/12 00:04:32 by adubedat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

MAKEFLAGS += --no-print-directory

SRC_NAME =  main.c \
            bonus.c \
            operations_p1.c \
            operations_p2.c \
            check_error.c \
            solve.c \

OBJ = $(SRC_NAME:.c=.o)

.SILENT:

all: $(NAME)

libft/libft.a:
	@make -C libft/

$(NAME): libft/libft.a $(OBJ)
	$(CC) $(WFLAGS) -L libft -lft $(OBJ) -o $(NAME)
	printf "\e[32m----------------------------------\e[36m\n"
	printf "\e[32m[✔]\e[36m $@"
	printf "\n\e[32m----------------------------------\e[36m"
	printf "\033[0m\n"

%.o: %.c
	$(CC) $(WFLAGS) -c -o $@ $^
	printf "\e[32m[✔]\e[36m $@"
	printf "\033[0m\n"

clean:
	@make -C libft/ clean
	rm -f $(OBJ)
	printf "\e[31m----------------------------------\n"
	printf "[✔]\e[36m $(NAME): Objects deleted\n"
	printf "\e[31m----------------------------------\e[36m"
	printf "\033[0m\n"

fclean: clean
	@make -C libft/ fclean
	rm -f $(NAME)
	printf "\e[31m----------------------------------\n"
	printf "[✔]\e[36m $(NAME): All deleted\n"
	printf "\e[31m----------------------------------\e[36m"
	printf "\033[0m\n"
	@make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re

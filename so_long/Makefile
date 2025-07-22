# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvidal <dvidal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/11 15:05:29 by dvidal            #+#    #+#              #
#    Updated: 2025/07/18 12:15:14 by dvidal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

CC := cc
CFLAGS := -Wall -Werror -Wextra -g
LFLAGS := -Lminilibx-linux -lmlx_Linux -lX11 -lXext -Llibft -lft -Lprintf -lftprintf

SRC := so_long.c map.c rendermap.c movement.c checker.c checker2.c init.c

OBJ := $(SRC:.c=.o)

HEADER := so_long.h

RM := rm -f

REPO := https://github.com/42paris/minilibx-linux.git

MLX_DIR := ./minilibx-linux/

all: $(NAME)

$(NAME): $(OBJ)

	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C ./libft
	$(MAKE) -C ./printf
	$(CC)   $(OBJ) -o $(NAME) $(LFLAGS)

clean:
	$(RM) $(OBJ)
	$(MAKE) -C ./printf clean
	$(MAKE) -C ./libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ./printf fclean
	$(MAKE) -C ./libft fclean

mlx:
	git clone $(REPO)


del: fclean
	rm -rf $(MLX_DIR)

re: fclean all
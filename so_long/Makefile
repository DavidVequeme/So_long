# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvidal <dvidal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/11 15:05:29 by dvidal            #+#    #+#              #
#    Updated: 2025/07/09 13:02:17 by dvidal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

CC := cc -g
CFLAGS := -g
LFLAGS := -Lminilibx-linux -lmlx_Linux -lX11 -lXext

SRC_A := libft/libft.a printf/libftprintf.a
SRC := so_long.c 

OBJ := $(SRC:.c=.o)

HEADER := so_long.h

RM := rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC)   $(OBJ) $(SRC_A) -o $(NAME) $(LFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
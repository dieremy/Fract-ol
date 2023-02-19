# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: robegarc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 10:51:10 by robegarc          #+#    #+#              #
#    Updated: 2023/02/19 10:42:54 by robegarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/fractal.c srcs/algos.c srcs/event.c srcs/plane.c srcs/user_inter.c
COMP = gcc -Wall -Wextra -Werror -Ofast
MLX = -lmlx -framework OpenGL -framework AppKit
NAME = fractal
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		@$(COMP) $(OBJS) $(MLX) -o $(NAME)

clean :
	@rm -rf $(OBJS)

fclean :	clean
	@rm -rf $(NAME)

re :	fclean all

.PHONY: clean fclean re all

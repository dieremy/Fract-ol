# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: robegarc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 10:51:10 by robegarc          #+#    #+#              #
#    Updated: 2023/02/10 10:51:15 by robegarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = fractal.c algos.c event.c
COMP = gcc -Wall -Wextra -Werror -Ofast
MLX = -Lmlx_linux -lmlx_Linux -Lminilibx-linux -Imlx_linux -lXext -lX11 -lm -lz
NAME = fractal
OBJS = $(SRCS:.c=.o)

%.o: %.c
	@$(COMP) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	@$(COMP) $(OBJS) $(MLX) -o $(NAME)
	@echo "\033[0;94m./${NAME} has been created\033[0m"

clean :
	@rm -rf $(OBJS)
	@echo "\033[0;35mOBJS deleted.\033[0m"

fclean : clean
	@rm -rf $(NAME)
	@echo "\033[0;35m./${NAME} deleted\033[0m"

re : fclean all
	@echo "\033[0;94mRESTART\033[0m"

.PHONY: clean fclean re all

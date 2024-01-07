# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: robegarc <robegarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 10:51:10 by robegarc          #+#    #+#              #
#    Updated: 2023/07/31 16:27:27 by robegarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# EXECUTABLE
NAME = fractal


# SRC AND OBJ FILES
SRCS = srcs/fractal.c srcs/algos.c srcs/event.c srcs/utils.c
OBJS = $(SRCS:.c=.o)


# LIBRARY
MLX_DIR_LNX = include/minilibx/minilibx-linux/
MLX_LNX = -L$(MLX_DIR_LNX) -lmlx_Linux -Lminilibx-linux -Imlx_linux -lXext -lX11 -lm -lz

MLX_DIR_MAC = include/minilibx/minilibx_mac/
MLX_MAC = -lmlx -framework OpenGL -framework AppKit


# COMPILE
CC = gcc
FLAG = -Wall -Wextra -Werror -Ofast -g -Iinclude/


# COLORS
ORANGE = \033[0;35m
VIOLET = \033[0;94m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
PURPLE =  \033[0;95m
CYAN = \033[0;96m
NONE = \033[0m


# RULEZ
OS = ${shell uname}

%.o: %.c
	@$(CC) $(FLAG) -c $< -o $@


$(NAME): $(OBJS)
	@echo "Compiling $(NAME)..."

ifeq ($(OS), Darwin)
	@make mac
else
	@make linux
endif

	@espeak "compiled muddafucka"
	@echo "$(NAME) compiled successfully."


all: $(NAME)


linux:
	@make all -s -C $(MLX_DIR_LNX)
	@echo "Compiling Linux mlx..."
	@$(CC) $(FLAG) $(OBJS) $(MLX_LNX) -o $(NAME) -g
	@clear


mac:
	@make -s -C $(MLX_DIR_MAC)
	@echo "Compiling Mac mlx..."
	@$(CC) $(FLAG) $(OBJS) $(MLX_MAC) -o $(NAME) -g
	@printf "AS PER CALCULATIONS, YOU ARE HERE AFTER A COMPILATION ISSUE.\n- RELAX, YOU ONLY HAVE TO COMPRESS MINILIBX DIRECTORY.\n- ADD tar -xvf  WHEN COMPILING FILES.\n- ADD tar -cvf WHEN CLEANING FILES.\n"
	#@clear


clean :

ifeq ($(OS), Darwin)
	@make clean -s -C ${MLX_DIR_MAC}
else
	@make clean -s -C ${MLX_DIR_LNX}
endif

	@rm -rf $(OBJS)
	@echo "OBJS deleted."


fclean : clean
	@rm -rf $(NAME)
	@echo "./${NAME} deleted"


re : fclean all clean
	@echo "RESTART"


.PHONY: clean fclean re all linux mac

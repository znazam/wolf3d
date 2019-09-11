# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juboyer <juboyer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/09 10:44:14 by znazam            #+#    #+#              #
#    Updated: 2019/09/10 14:06:28 by juboyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./srcs/

SRC_NAME = main.c error.c images.c read.c raycasting.c position.c

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ = $(patsubst %.c, %.o, $(SRC))

NAME = wolf3d

HEADERS = wolf3d.h

FLAGS = -Wextra -Werror -Wall -I libft -I GNL -I .

all: LIBFT GNL LIBVEC $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) LIBVEC/libvec.a libft/libft.a GNL/get_next_line.o -lmlx -framework OpenGL -framework AppKit
	@echo "\033[36mAll Libraries Compiled."
LIBFT:
	@git submodule init libft
	@git submodule update libft
	@make -C libft
	@echo "\033[94mLibft Inserted."

GNL:
	@git submodule init GNL
	@git submodule update GNL
	@gcc -c $(FLAGS) GNL/get_next_line.c -o GNL/get_next_line.o
	@echo "\033[94mGNL Inserted."
	
LIBVEC:
	@git submodule init libvec
	@git submodule update libvec
	@make -C libvec
	@echo "\033[94mLibvec Inserted."

$(SRC_PATH)%.o: $(SRC_PATH)%.c $(HEADERS)
	@gcc -g -c $(FLAGS) -o $@ $<
	@echo "\033[94mRemade files."

clean:
	@rm -f $(OBJ)
	@echo "\033[94mAll Object Files Removed."

fclean: clean
	@rm -f $(NAME)
	@rm GNL/get_next_line.o
	@make -C libft fclean
	@make -C libvec fclean
	@echo "\033[94mAll Library Object Files Removed."

re: fclean all

updateSubmodules:
	@make fclean
	@git submodule foreach git checkout master
	@git submodule foreach git pull origin master
	@git add .
	@git commit -m "submodule update"
	@git push
	@echo "\033[94mSubmodules Updated."

.PHONY: LIBFT LIBVEC re fclean clean GNL all updateSubmodules

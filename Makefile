# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maginist <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/31 11:45:22 by maginist          #+#    #+#              #
#    Updated: 2019/05/31 12:05:14 by maginist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = asm
NAME2 = corewar
OBJ_PATH1 = ./obj_asm
OBJ_PATH2 = ./obj_
SRC_PATH1 = ./asm_src/
SRC_PATH2 = ./vm_src

SRCS1 =

SRCS2 =

LIBFT =

OBJ_NAME1 = $(SRCS1:.c=.o)
OBJ_NAME2 = $(SRCS2:.c=.o)
LIB = libft/
CC = gcc
CFLAGS = -Wall -Werror -Wextra
INC = -I./includes
SRC1 = $(addprefix $(SRC_PATH1)/,$(SRCS1))
OBJ1 = $(addprefix $(OBJ_PATH1)/,$(OBJ_NAME1))
SRC2 = $(addprefix $(SRC_PATH2)/,$(SRCS2))
OBJ2 = $(addprefix $(OBJ_PATH2)/,$(OBJ_NAME2))

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ_PATH1) $(OBJ1)
	@make -C $(LIB) -j
	@cp libft/libft.a ./
	@$(CC) $(CFLAGS) -o $(NAME1) $(OBJ1) libft.a
	@echo "\033[33;36m===  <ASM DONE> ===\033[00m"

$(NAME2): $(OBJ_PATH2) $(OBJ2)
	@make -C $(LIB) -j
	@cp libft/libft.a ./
	@$(CC) $(CFLAGS) -o $(NAME2) $(OBJ2) libft.a
	@echo "\033[33;36m===  <COREWAR DONE> ===\033[00m"

$(OBJ_PATH1)/%.o : $(SRC_PATH1)/%.c
	@$(CC) $(CFLAGS) -c $? $(INC) -o $@

$(OBJ_PATH2)/%.o : $(SRC_PATH2)/%.c
	@$(CC) $(CFLAGS) -c $? $(INC) -o $@

clean:
	@make -C $(LIB) clean
	@rm -rf ./obj_c
	@rm -rf ./obj_ps
	@rm -rf ./libft.a
	@echo "\033[33;11m===  <obj cleaned>  ===\033[00m"

$(OBJ_PATH1):
	@mkdir -p $(OBJ_PATH1)

$(OBJ_PATH2):
	@mkdir -p $(OBJ_PATH2)

fclean: clean
	@make fclean -C $(LIB)
	@rm -f $(NAME1)
	@rm -f $(NAME2)
	@echo "\033[33;12m=== <Project cleaned> === \033[00m"

re: fclean all

.PHONY : all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/31 11:45:22 by maginist          #+#    #+#              #
#    Updated: 2019/07/31 12:51:55 by floblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = asm
NAME2 = corewar
OBJ_PATH1 = ./obj_asm
OBJ_PATH2 = ./obj_vm
SRC_PATH1 = ./asm_src/
SRC_PATH2 = ./vm_src

SRCS1 = fct_for_used_lab.c\
		free_structs.c\
		gest_lab.c\
		gestion_arg.c\
		gestion_one_arg.c\
		gestion_two_args.c\
		gestion_three_args1.c\
		gestion_three_args2.c\
		gnl_find_mod.c\
		main.c\
		more_utils.c\
		parsing_annexe_fct.c\
		parsing_stock_first_half.c\
		stock_data.c\
		utils.c

SRCS2 =	main.c\
		parsing_args.c\
		stock_champs.c\
		init_vm.c\
		gest_champ.c\
		refresh_visual.c\
		visual.c\
		vm.c\
		run_vm.c\
		vm_util.c\
		get_params.c\
		fvm_tab_files.c\
		op.c


OBJ_NAME1 = $(SRCS1:.c=.o)
OBJ_NAME2 = $(SRCS2:.c=.o)
LIB = libprintf/
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 #//////G3\\\\\\#
INC = -I./includes
SRC1 = $(addprefix $(SRC_PATH1)/,$(SRCS1))
OBJ1 = $(addprefix $(OBJ_PATH1)/,$(OBJ_NAME1))
SRC2 = $(addprefix $(SRC_PATH2)/,$(SRCS2))
OBJ2 = $(addprefix $(OBJ_PATH2)/,$(OBJ_NAME2))

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ_PATH1) $(OBJ1)
	@make -C $(LIB) -j
	@cp libprintf/libprintf.a ./
	@$(CC) $(CFLAGS) -o $(NAME1) $(OBJ1) libprintf.a
	@echo "\033[33;36m===  <ASM DONE> ===\033[00m"

$(NAME2): $(OBJ_PATH2) $(OBJ2)
	@make -C $(LIB) -j
	@cp libprintf/libprintf.a ./
	@$(CC) $(CFLAGS) -o $(NAME2) $(OBJ2) libprintf.a -lncurses
	@echo "\033[33;36m===  <COREWAR DONE> ===\033[00m"

$(OBJ_PATH1)/%.o : $(SRC_PATH1)/%.c
	@$(CC) $(CFLAGS) -c $? $(INC) -o $@

$(OBJ_PATH2)/%.o : $(SRC_PATH2)/%.c
	@$(CC) $(CFLAGS) -c $? $(INC) -o $@

clean:
	@make -C $(LIB) clean
	@rm -rf ./obj_asm
	@rm -rf ./obj_vm
	@rm -rf ./libprintf.a
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
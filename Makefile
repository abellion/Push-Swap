# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abellion <abellion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/17 16:33:37 by abellion          #+#    #+#              #
#    Updated: 2015/02/25 15:17:42 by abellion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_C =	program_files/src/main.c \
		program_files/src/utilities/utilities_type.c \
		program_files/src/utilities/utilities_args.c \
		program_files/src/utilities/utilities_sort.c \
		program_files/src/utilities/utilities_tab.c \
		program_files/src/utilities/utilities_lst.c \
		program_files/src/utilities/utilities_lst2.c \
		program_files/src/args_checker/args_checker_controller.c \
		program_files/src/piles_operations/pile_swap.c \
		program_files/src/piles_operations/pile_rotate.c \
		program_files/src/piles_operations/pile_rev_rotate.c \
		program_files/src/piles_operations/pile_push.c \
		program_files/src/calculator/calculator_piles_manager.c \
		program_files/src/calculator/calculator_values_manager.c \
		program_files/src/calculator/calculator_controller.c \
		program_files/src/calculator/calculator_operations.c \
		program_files/src/printer/printer_controller.c \
		program_files/src/printer/printer_operations.c \
		program_files/src/printer/printer_infos.c \
		program_files/src/printer/printer_details.c

OBJ = $(patsubst %.c, %.o, $(notdir $(SRC_C)))

SOFT_NAME = push_swap

C_BEG = $(shell echo "\033[0;32m")

C_END = $(shell echo "\033[0m")

all: $(SOFT_NAME)

$(SOFT_NAME): $(SRC_C)
	make -C libft/
	@echo "\n$(C_BEG)==========	SOFTWARE COMPILATION	==========$(C_END)"
	gcc -g -Wall -Wextra -Werror -I libft/includes/ -c $(SRC_C)
	@echo "\n$(C_BEG)==========	CREATING EXECUTBLE FILE	==========$(C_END)"
	gcc -g -o $(SOFT_NAME) $(OBJ) -L libft/ -lft

clean:
	make -C libft/ clean
	@echo "\n$(C_BEG)==========	DELETING OBJECTS FILES	==========$(C_END)"
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	@echo "\n$(C_BEG)==========	DELETING SOFT FILE		==========$(C_END)"
	rm -rf $(SOFT_NAME)

re: fclean all

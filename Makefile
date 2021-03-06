# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 01:35:58 by bmugnol-          #+#    #+#              #
#    Updated: 2022/06/09 20:44:24 by bmugnol-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME	:=	push_swap

# GENERAL OPTIONS
# C Compiler
CC		:=	gcc
# Compiler flags
CFLAGS	:=	-Wall -Wextra -Werror
# Removal tool
RM		:=	rm -rf


# PUSH_SWAP
# Headers
HEADER_DIR	:=	inc		src/algorithm		src/linked_list		src/operation
HEADER		:=	push_swap.h		struct.h	\
				algorithm.h					\
				list.h						\
				operation.h
H_INCLUDE	:=	$(addprefix -I, $(HEADER_DIR))

# SOURCE
SRC_DIR		:=	src 	src/algorithm		src/linked_list		src/operation
SRC			:=	push_swap.c										\
				algorithm.c		aux.c	radix.c		sort_low.c	\
				list_add.c 	list_get.c	list_remove.c			\
				push.c rotate.c reverse_rotate.c swap.c

# Object
OBJ_DIR		:=	obj
OBJ			:=	$(SRC:%.c=$(OBJ_DIR)/%.o)


# LIBFT
LIBFT_DIR	:=	../../Fase_1/libft

LIBFT_H_DIR	:=	$(LIBFT_DIR)/inc
LIBFT_H_INC	:=	-I$(LIBFT_H_DIR)

LIBFT_LIB	:=	$(LIBFT_DIR)/libft.a


# Inclusions:
INCLUDE		:=	$(H_INCLUDE) $(LIBFT_H_INC)

# vpath
vpath	%.h		$(HEADER_DIR)
vpath	%.c		$(SRC_DIR)

# -----------------------RULES------------------------------------------------ #
.PHONY: all norm clean fclean re

# Creates NAME
all: $(NAME)

# Compiles OBJ and LIBFT_LIB into the program NAME
$(NAME): $(LIBFT_LIB) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT_LIB) $(INCLUDE)

# Compiling SRC into OBJ
$(OBJ): $(OBJ_DIR)/%.o: %.c $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

# Directory making
$(OBJ_DIR):
	@mkdir -p $@

# Libft compiling
$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

# Norm: checks code for norm errors
norm:
	@$(MAKE) -C $(LIBFT_DIR) norm
	@norminette | grep "Error" | cat

# Clean: removes objects' and precompiled headers' directories
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ_DIR)

# Full clean: same as 'clean', but removes the generated libraries as well
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

# Remake: full cleans and runs 'all' rule
re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/15 15:54:01 by vsavilov          #+#    #+#              #
#    Updated: 2021/11/16 13:19:55 by vsavilov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##############################
###   Compiler and flags   ###
##############################

CC = gcc

CFLAGS = -Wall -Werror -Wextra

CFLAGS += -I ./$(INC_PATH)

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

DEBUG: CFLAGS += -fsanitize=address -g3

########################
###   Source items   ###
########################

SRCS_NAME = 

#######################
###   Directories   ###
#######################

SRC_PATH = src

OBJ_PATH = obj

INC_PATH = inc

LIB_PATH = lib

LIBFT_PATH = libft

MLX_PATH = minilibx_macos

#####################
###   Make rule   ###
#####################

MAKE = make

############################
###   Program/s name/s   ###
############################

NAME = fdf

LIBFT_NAME = libft.a

LMLX_NAME = libmlx.a

#################################
###   Rules can be executed   ###
#################################

all: $(NAME)

debug: $(NAME)

##########################
###   Create objects   ###
##########################

OBJS_NAME = $(SRCS_NAME:%.c=%.o)

SRCS = $(addprefix $(SRC_PATH)/, $(SRCS_NAME))

OBJS = $(addprefix $(OBJ_PATH)/, $(OBJS_NAME))


#######################
###   Create libs   ###
#######################

LIBFT =	$(LIB_PATH)/$(LIBFT_PATH)

LMLX = $(LIB_PATH)/$(MLX_PATH)

#######################
###   Objects dir   ###
#######################

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
		@mkdir -p $(OBJ_PATH) 2> /dev/null

$(LIBS_DIR):
		@mkdir -p $(LIBS-DIR) 2> /dev/null

#########################
###   Compile libs   ###
#########################

$(LIBFT_NAME):
	@$(MAKE) all -sC $(LIBFT)
	@cp -r $(addprefix $(LIBFT)/, $(LIBFT_NAME)) $(LIBFT_NAME)

$(LMLX_NAME):
	@$(MAKE) all -sC $(LMLX)
	@cp $(addprefix $(LMLX)/, $(LMLX_NAME)) $(LMLX_NAME)

#####################
###   Compile.o   ###
#####################

.o:.c
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(LIBFT_NAME) $(LMLX_NAME) $(OBJS)
	@$(CC) $(CFLAGS) $(MLX) $(OBJS) -o $(NAME)

#######################
###   Other rules   ###
#######################

.PHONY: all clean fclean re

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@$(MAKE) fclean -sC $(LIBFT)
	@$(MAKE) clean -sC $(LMLX)
	@rm -rf $(NAME)
	@rm $(LIBFT_NAME)
	@rm $(LMLX_NAME)

re: fclean all

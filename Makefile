# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/15 15:54:01 by vsavilov          #+#    #+#              #
#    Updated: 2021/12/17 17:19:57 by Vsavilov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############################
###   Program/s name/s   ###
############################

NAME = fdf

LIBFT_NAME = libft.a

LMLX_NAME = libmlx.a

##############################
###   Compiler and flags   ###
##############################

CC = gcc

CFLAGS = -Wall -Werror -Wextra

CFLAGS += -I ./$(INC_PATH) -I ./$(LIBFT)/inc -I ./$(LMLX)

CFLAGS += -O3

MLX = -framework OpenGL -framework AppKit

CFLAGS += -fsanitize=address -g3

#################
###   Paths   ###
#################

SRC_PATH = src

OBJ_PATH = obj

INC_PATH = inc

LIB_PATH = lib

LIBFT_PATH = libft

MLX_PATH = minilibx_macos

########################
###   Source items   ###
########################

SRCS_NAME = fdf.c \
	init_struct.c \
	get_next_line.c \
	keys_close.c \
	error_msg.c \
	mlx_functions.c \
	utils.c \
	draw.c \
	mlx_utils.c \
	read_file.c

#####################
###   Make rule   ###
#####################

MAKE = make

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

#################################
###   Rules can be executed   ###
#################################

all: $(NAME)

debug: $(NAME)

#######################
###   Objects dir   ###
#######################

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH) 2> /dev/null

$(LIBS_DIR):
	mkdir -p $(LIBS-DIR) 2> /dev/null

#########################
###   Compile libs   ###
#########################

$(LIBFT_NAME):
	$(MAKE) all -sC $(LIBFT)
	cp -r $(addprefix $(LIBFT)/, $(LIBFT_NAME)) $(LIBFT_NAME)

$(LMLX_NAME):
	$(MAKE) all -sC $(LMLX)
	cp $(addprefix $(LMLX)/, $(LMLX_NAME)) $(LMLX_NAME)

#####################
###   Compile.o   ###
#####################

$(NAME): $(LMLX_NAME) $(LIBFT_NAME) $(OBJS) 
	$(CC) $(CFLAGS) $(MLX) $(OBJS) -o $(NAME) $(LMLX_NAME) $(LIBFT_NAME)

#######################
###   Other rules   ###
#######################

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	$(MAKE) fclean -sC $(LIBFT)
	$(MAKE) clean -sC $(LMLX)
	rm -rf $(NAME)
	rm $(LIBFT_NAME)
	rm $(LMLX_NAME)

re: fclean all

.PHONY: all clean fclean re

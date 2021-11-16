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

LIB_PATH = lib


#####################
###   Make rule   ###
#####################

MAKE = make

############################
###   Program/s name/s   ###
############################

NAME = fdf

LIB_NAME = libft.a

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
###   Objects dir   ###
#######################

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) -I. -c $< -o $@

$(OBJ_PATH):
		@mkdir -p $(OBJ_PATH) 2> /dev/null

#########################
###   Compile libft   ###
#########################

$(LIB_NAME):
	$(MAKE) all -sC $(LIB_PATH)


#####################
###   Compile.o   ###
#####################

.o:.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIB_NAME) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

#######################
###   Other rules   ###
#######################

.PHONY: all clean fclean re

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	$(MAKE) fclean -sC $(LIB_PATH)
	rm -rf $(NAME)

re: fclean all

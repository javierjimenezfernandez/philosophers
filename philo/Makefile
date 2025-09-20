# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javjimen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 20:31:03 by javjimen          #+#    #+#              #
#    Updated: 2025/09/27 20:31:43 by javjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME		= philo


# Operating system name
UNAME		= $(shell uname)


# Dependancies
INCLUDES	= -Iinc
ifeq (UNAME, Linux)
	INCLUDES +=
else
	INCLUDES +=
endif


# List of source files
SRC_DIR		= src/
SRC			= $(addprefix $(SRC_DIR), ft_utils.c \
									  time_utils.c \
									  print_utils.c \
									  error_handler.c \
									  input_control.c \
									  init.c \
									  watcher.c \
									  philo_actions.c \
									  threads_create.c \
									  philosophers.c)


# List of object files
OBJ_DIR		= obj/
OBJ			= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)


# List of header files
INC_DIR		= inc/
INC			= $(addprefix inc/, philosophers.h)


# Compilation flags
CC			= cc
RM			= rm -rf
AR			= ar
DIR_DUP		= mkdir -p $(@D)

CFLAGS 		+= -Wall -Wextra -Werror
ARFLAGS		= -r -c -s

ifeq (UNAME, Linux)
	EXTRA_FLAGS =
else
	EXTRA_FLAGS =
endif

SANITIZE	= $(CFLAGS) -fsanitize=address


# Rule name protection
.PHONY:		all clean fclean re sanitize

all: 		$(NAME)


# Make rules
$(NAME):	$(OBJ) $(INC)
			$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) $(EXTRA_FLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			$(DIR_DUP)
			$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@

clean:
			$(RM) $(OBJ_DIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

sanitize:	$(OBJ) $(INC)
			$(CC) $(SANITIZE) $(OBJ) -o $(NAME) $(EXTRA_FLAGS)

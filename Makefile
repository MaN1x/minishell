# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxim <maxim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/05 16:05:40 by maxim             #+#    #+#              #
#    Updated: 2020/07/11 16:27:07 by maxim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAGS = -Wall -Wextra -Werror

LIB_PATH = libft/
INC_PATH = includes/
SRC_PATH = src/
OBJ_PATH = obj/

LIB_NAME = libft.a

INC_FILES = minishell.h

SRC_FILES = 		main.c \
            		parse.c \
            		parse_parameter_extension.c \
            		parse_tilda.c \
            		print_err.c \
            		run.c \
            		run_builtin.c\
            		ft_cd.c\
            		ft_echo.c\
            		ft_exit.c\
            		ft_setenv.c\
            		ft_unsetenv.c\
            		env.c\
            		find_in_env.c

SRCS = $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_PATH), $(SRC_FILES:.c=.o))
LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))
INC = $(addprefix $(INC_PATH), $(INC_FILES))

all: $(NAME)

$(NAME): $(LIB) $(OBJ_PATH) $(OBJS)
	gcc $(FLAGS) -o $(NAME) $(OBJS) -L$(LIB_PATH) -lft

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(LIB):
	make -C $(LIB_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC)
	gcc $(FLAGS) -I$(INC_PATH) -I$(LIB_PATH) -o $@ -c $<

clean:
	rm -rf $(OBJ_PATH)
	make -C $(LIB_PATH) clean

fclean: clean
	rm $(NAME)
	make -C $(LIB_PATH) fclean

re: fclean all

.PHONY: all fclean clean re

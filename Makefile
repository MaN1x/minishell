# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxim <maxim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/05 16:05:40 by maxim             #+#    #+#              #
#    Updated: 2020/07/08 04:10:03 by maxim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC_PATH = src/
LIB_PATH = libft/
OBJ_PATH = obj/
INC_PATH = includes/ $(LIB_PATH)

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
OBJ_FILES = $(SRC_FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror

SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_FILES))
INC = $(addprefix -I, $(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIB_PATH)
		gcc $(FLAGS) $(OBJ)  $(INC) -L $(LIB_PATH) -lft -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		mkdir -p $(OBJ_PATH)
		gcc $(FLAGS)  $(INC) -c $< -o $@

clean:
		make -C $(LIB_PATH)/ clean
		/bin/rm -rf $(OBJ_PATH)

fclean: clean
		make -C $(LIB_PATH)/ fclean
		/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re $(NAME)

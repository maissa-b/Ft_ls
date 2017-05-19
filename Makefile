# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/14 20:41:38 by maissa-b          #+#    #+#              #
#    Updated: 2015/12/16 15:35:55 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CFLAGS = -Wall -Werror -Wextra

CC = gcc

SRC = ft_parse.c ft_rights_tools.c ft_argd_tools.c ft_argf_tools.c ft_tools.c \
	  ft_sort_argd.c ft_sort_argf.c ft_tools2.c ft_opt_tools.c ft_init.c \
	  ft_list_argd.c ft_list_argf.c ft_opt_l.c ft_errors.c ft_destroy.c \
	  ft_opt.c ft_ls.c ft_parse_tools.c ft_aff_optl.c ft_opt_r_maj.c

OBJ = $(SRC:%.c=%.o)
INCLUDE = ft_ls.h
LIB = libft/
LIB_FLAGS = libft/bin/libft.a
SRC_DIR = srcs/
OBJ_DIR = objs/
INCLIB_DIR	= libft/includes/
INC_DIR = includes/

SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
INCS = $(addprefix $(INC_DIR), $(HEADER))

.SILENT:

all: create_repos compile_lib send_mesage $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L libft/bin -lft
	printf "\033[32m\n\n$(NAME) created.\n\033[m"

create_repos:
	mkdir -p $(OBJ_DIR)

send_mesage:
	printf "\033[1m_______________________________________________________________________\n\n\033[m"
	printf "\033[33mCompiling $(NAME) : \n\033[m"

compile_lib:
	make -C $(LIB)

objs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(INCLIB_DIR) -o $@ -c $<
	printf "\033[1;34m. \033[m"

clean:
	Make -C libft/ clean
	rm -rf $(OBJS)
	rm -rf $(OBJ_DIR)
	echo "\033[31mRemoving objs in $(NAME)\033[m"

fclean:	clean
	Make -C libft/ fclean
	rm -rf $(NAME)
	echo "\033[31mRemoving $(NAME)\033[m"

re: fclean all

header:
	echo "\033[32mCheck header.\033[m"
	echo "\033[1mBY\033[m"
	grep "By" $(INCS) $(SRCS) | cut -c1-70
	echo "\033[1mCREATED\033[m"
	grep "Created" $(INCS) $(SRCS) | cut -c1-70

user:
	echo "\033[32mCheck fichier auteur.\033[m"
	cat -e auteur
	whoami | cat -e

normi_lib:
	make -C libft/ normi

normi_ls:
	norminette $(SRC_DIR) $(INC_DIR)
	echo "\033[32m$(NAME) : Norminette done.\033[0m"

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/25 04:41:51 by maissa-b          #+#    #+#              #
#    Updated: 2015/12/18 17:23:39 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_travel.a

SRC =	ft_strlen.c ft_strmax.c ft_strmin.c count_int_in_str.c ft_tablen.c \
		ft_isalnum.c ft_isalpha.c ft_isblank.c ft_iscntrl.c ft_isdigit.c \
		ft_isgraph.c ft_islower.c ft_isprint.c ft_ispunct.c ft_isspace.c \
		ft_isupper.c ft_isxdigit.c ft_strequ.c ft_strnequ.c ft_strcmp.c \
		ft_strncmp.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
		ft_strlexicocmp.c ft_memchr.c ft_memcmp.c ft_find_index_tab.c \
		ft_intcmp.c ft_intlen.c ft_iseof.c ft_strnrchr.c

OBJ = $(SRC:.c=.o)
INCLUDE = libft_travel.h
CC = gcc
CFLAGS = -Wall -Werror -Wextra
PATH_ALL_BIN = ../../bin/

SRC_DIR = srcs/
OBJ_DIR = objs/
INC_DIR = includes/
BIN_DIR = bin/

SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
INCS = $(addprefix $(INC_DIR), $(INCLUDE))
BINS = $(addprefix $(BIN_DIR), $(NAME))

.SILENT:

all: create_repos send_mesage $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -c $(SRCS) -I $(INC_DIR)
		mv $(OBJ) $(OBJ_DIR)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)
		cp $(NAME) $(PATH_ALL_BIN)

create_repos:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(PATH_ALL_BIN)

send_mesage:
	echo "\033[33m\n\nCompiling $(NAME) : \033[m"

objs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<
	printf "\033[1;34m. \033[m"

normi:
	norminette $(SRC_DIR) $(INC_DIR) | grep "Error" || echo "\033[1mNo error.\033[m"
	norminette $(SRC_DIR) $(INC_DIR) | grep "Warning" || echo "\033[1mNo warning.\033[m"

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

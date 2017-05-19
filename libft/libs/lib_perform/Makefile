# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/25 04:42:05 by maissa-b          #+#    #+#              #
#    Updated: 2015/12/23 19:02:32 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_perform.a

SRC =	ft_tolower.c ft_toupper.c ft_itoa.c ft_striter.c ft_striteri.c \
		ft_atoi.c ft_strlcat.c ft_strcat.c ft_strncat.c \
		ft_strnew.c ft_strtrim.c ft_strcpy.c ft_strncpy.c ft_strdup.c \
		ft_strjoin.c ft_multijoin.c ft_strmap.c ft_strmapi.c ft_strsub.c \
		ft_cutstr.c ft_charreplace.c ft_strreplace.c ft_tab_dup.c \
		ft_strsplit.c ft_tabreplace.c ft_memalloc.c ft_memset.c ft_memcpy.c \
		ft_memccpy.c ft_memmove.c ft_strclr.c ft_memdel.c ft_bzero.c \
		ft_strdel.c ft_multifruee.c ft_tabclr.c ft_swap.c ft_swap_str.c \
		ft_strrev.c ft_strc_to_stri.c ft_tabc_to_tabi.c ft_swapi.c ft_strlower.c\
		ft_strupper.c ft_sort_ascii_tab.c ft_free_and_join.c

OBJ = $(SRC:.c=.o)
INCLUDE = libft_perform.h
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

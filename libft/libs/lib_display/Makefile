# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/25 04:40:21 by maissa-b          #+#    #+#              #
#    Updated: 2015/11/02 20:29:03 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_display.a

SRC =	ft_putchar.c ft_put_n_char.c ft_putchar_fd.c ft_putchar_color.c \
		ft_putchar_color_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putnbr_color.c \
		ft_putnbr_color_fd.c ft_putstr.c ft_puts_until.c ft_putstr_fd.c \
		ft_putstr_color.c ft_putstr_color_fd.c ft_putendl.c ft_putendl_fd.c \
		ft_putendl_color.c ft_putendl_color_fd.c ft_aff_tabc.c ok.c \
		ft_before_str.c ft_before_nbr.c ft_after_str.c ft_after_nbr.c

OBJ = $(SRC:.c=.o)
INCLUDE = libft_display.h
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

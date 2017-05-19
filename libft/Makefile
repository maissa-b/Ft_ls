# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/24 15:20:46 by maissa-b          #+#    #+#              #
#    Updated: 2015/07/25 09:59:23 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

BIN_DIR = bin/
LIB_DIR = libs/
INC_DIR = includes/

LIB_TRAVEL = libs/lib_travel
LIB_PERFORM = libs/lib_perform
LIB_DISPLAY = libs/lib_display

BIN_TRAVEL = libft_travel.a
BIN_PERFORM = libft_perform.a
BIN_DISPLAY = libft_display.a

CC_LIBTRAVEL = make -C $(LIB_TRAVEL) 
CC_LIBPERFORM = make -C $(LIB_PERFORM)
CC_LIBDISPLAY = make -C $(LIB_DISPLAY)

BINS_TRAVEL = $(addprefix $(BIN_DIR), $(BIN_TRAVEL))
BINS_PERFORM = $(addprefix $(BIN_DIR), $(BIN_PERFORM))
BINS_DISPLAY = $(addprefix $(BIN_DIR), $(BIN_DISPLAY))

NORME_H_TRAVEL = libs/lib_travel/includes/
NOME_C_TRAVEL = libs/lib_travel/srcs/
NORME_H_PERFORM = libs/lib_perform/includes/
NOME_C_PERFORM = libs/lib_perform/srcs/
NORME_H_DISPLAY = libs/lib_display/includes/
NOME_C_DISPLAY = libs/lib_display/srcs/

MERGE = libtool -static -o $(NAME) $(BINS_TRAVEL) $(BINS_PERFORM) $(BINS_DISPLAY)

.SILENT:

all: $(NAME)

$(NAME):
	$(CC_LIBTRAVEL)
	$(CC_LIBPERFORM)
	$(CC_LIBDISPLAY)
	$(MERGE)
	mv $(NAME) $(BIN_DIR)
	echo "\033[32m\n\n$(NAME) is create.\n\033[m"

clean:
	echo "\033[31m\nRemoving objs in libs\033[m"
	$(CC_LIBTRAVEL) clean
	$(CC_LIBPERFORM) clean
	$(CC_LIBDISPLAY) clean

fclean: clean
	echo "\033[31m\nRemoving $(NAME)\033[m"
	rm -rf $(BIN_DIR)
	rm -rf $(NAME)
	$(CC_LIBTRAVEL) fclean
	$(CC_LIBPERFORM) fclean
	$(CC_LIBDISPLAY) fclean

re: fclean all

normi:
	norminette $(INC_DIR) $(NORME_H_TRAVEL) $(NOME_C_TRAVEL) $(NORME_H_PERFORM) $(NOME_C_PERFORM) $(NORME_H_DISPLAY) $(NOME_C_DISPLAY)
	echo "\033[32m$(NAME) : Norminette done.\033[0m"

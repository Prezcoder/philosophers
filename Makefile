# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 10:27:08 by emlamoth          #+#    #+#              #
#    Updated: 2023/08/24 11:00:21 by fbouchar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c		\
		init_data.c	\
		utils.c		\
		utils2.c	\
		watching.c	\

HDRS = ./include/philo.h

SRCS_DIR = ./srcs/
OBJS_DIR = ./srcs/objs_philo/
OBJS = $(SRCS:$(SCRS_DIR)%.c=$(OBJS_DIR)%.o)

NAME = philo

CFLAGS = -Wall -Wextra -Werror -pthread #-fsanitize=thread

CC = gcc

GREEN = \033[1;32m
RED = \033[1;31m
NC = \033[0;0m

all: $(NAME)

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(HDRS) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "${GREEN}PHILO COMPILED${NC}"

leak: CFLAGS += -g
leak: all
	@reset
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes ./philo

clean:
	@rm -rf $(OBJS_DIR)
	@echo "${RED}PHILO OBJECTS DELETED${NC}"

fclean: clean
	@rm -f $(NAME)
	@echo "${RED}PHILO DELETED${NC}"

bonus: all

re: fclean all

.PHONY: all clean fclean re
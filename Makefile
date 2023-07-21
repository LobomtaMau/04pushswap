# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaptist <mbaptist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 11:11:18 by mbaptist          #+#    #+#              #
#    Updated: 2023/07/21 14:22:00 by mbaptist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = 	main.c \
		push_swap.c \
		cmd_push.c \
		cmd_rev_rotate.c \
		cmd_rotate.c \
		cmd_swap.c \
		errors.c \
		stack_create.c \
		stack_checker.c \
		stack_sort.c \
		auxiliar.c \

SRCS_DIR = src
OBJS_DIR = obj

SRCS_PATH = $(addprefix $(SRCS_DIR)/,$(SRCS))
OBJS_PATH = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS_PATH)
	$(CC) $^ -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
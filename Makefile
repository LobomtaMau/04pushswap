# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaptist <mbaptist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 11:11:18 by mbaptist          #+#    #+#              #
#    Updated: 2023/07/14 12:26:39 by mbaptist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = 	main.c \
		push_swap.c \
		auxiliar.c \
		errors.c \
		stack_fill.c \
		stack_algorithm.c \
		stack_algorithm2.c \
		cmd_stack_push.c \
		cmd_stack_rotate.c \
		cmd_stack_swap.c \
		cmd_stack_rev_rotate.c \

OBJS = $(SRCS:.c=.o)

ARCHIVE = push_swap.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar -rcs
RM = rm -fr

all: $(NAME)

$(NAME) : $(ARCHIVE)
		$(CC) $< -o $@

$(ARCHIVE): $(OBJS)
		$(AR) $(ARCHIVE) $^

%.o : %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS) $(ARCHIVE)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
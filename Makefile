# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/28 12:19:50 by mdahlstr          #+#    #+#              #
#    Updated: 2024/11/19 18:42:58 by mdahlstr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -rf

SRCS = main.c big_sort.c create_int_list.c parse_input.c push_swap_utils.c \
		initialise_nodes.c sort_stack_a.c sorting_utils.c \
		align_for_push.c errors_and_memory.c \
		operations/rotate_command.c operations/swap_command.c \
		operations/reverse_rotate_command.c operations/push_command.c

OBJS = $(SRCS:.c=.o)
NAME = push_swap
LIBFT = libft/libft.a
DEPS = include/push_swap.h

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT): 
	make -C libft

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(REMOVE) $(OBJS)
	make -C libft clean

fclean: clean
	$(REMOVE) $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re

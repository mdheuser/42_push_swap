# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/28 12:19:50 by mdahlstr          #+#    #+#              #
#    Updated: 2024/08/13 16:55:34 by mdahlstr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
REMOVE = rm -rf

SRCS = main.c create_int_list.c \
	commands/rotate_command.c commands/swap_command.c \
	commands/reverse_rotate_command.c commands/push_command.c \
	push_swap_utils.c process_argv.c sort_stack_a.c ##sorting_algorithm.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT): 
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(REMOVE) $(OBJS)
	make -C libft clean

fclean: clean
	$(REMOVE) $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re

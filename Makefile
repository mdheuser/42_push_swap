# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/28 12:19:50 by mdahlstr          #+#    #+#              #
#    Updated: 2024/08/11 22:27:57 by mdahlstr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
REMOVE = rm -rf

SRCS = main.c swap.c parse_array.c error_message.c create_int_list.c \
	sort_two_and_three.c check_if_sorted.c find_last_node.c rotate.c \
	reverse_rotate.c \
	##push.c sorting_algorithm.c
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

#this is a comment

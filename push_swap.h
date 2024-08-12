/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:21:47 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/08/12 16:07:10 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h> // read(), write()
# include <stdlib.h> // malloc(), free(), exit()
# include <limits.h>
# include <stdio.h> // REMOVE -------------------------------------------------------------
# include <stdbool.h>

typedef struct s_stack_node
{
	int					value;
	int					position;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
} t_stack_node;

int				main(int argc, char **argv);

// Checking
int				parse_array(char **argv, int size);
void			error_message(void);
int				check_if_sorted(t_stack_node *stack);
t_stack_node    *find_last_node(t_stack_node *node);
t_stack_node	*create_int_list(char **argv, int size);

// Commands 
void			swap_a(t_stack_node **stack_a);
void			swap_b(t_stack_node **stack_b);
void			swap_ab(t_stack_node **stack_a, t_stack_node **stack_b);

void    		rotate_a(t_stack_node **stack_a);
void    		rotate_b(t_stack_node **stack_b);
void    		rotate_ab(t_stack_node **stack_a, t_stack_node **stack_b);

void    		reverse_rotate_a(t_stack_node **stack_a);
void    		reverse_rotate_b(t_stack_node **stack_b);
void    		reverse_rotate_ab(t_stack_node **stack_a, t_stack_node **stack_b);

void    		push_a(t_stack_node **stack_a, t_stack_node **stack_b);
void    		push_b(t_stack_node **stack_b, t_stack_node **stack_a);

// Sorting
void    sort_two_numbers(t_stack_node **stack_a);
void    sort_three_numbers(t_stack_node **stack_a);

// TEMPORARY ///
void			printList(t_stack_node *head); ///////////// ------------------------------REMOVE

#endif 
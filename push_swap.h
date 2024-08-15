/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:21:47 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/08/15 14:31:11 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h> // read(), write()
# include <stdlib.h> // malloc(), free(), exit()
# include <limits.h>
# include <stdio.h> // REMOVE -------------------------------------------------------------
// # include <stdbool.h>

// Node structure
typedef struct s_stack_node
{
	int					value;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
} t_stack_node;

// Key functions
t_stack_node 	*process_argv(int argc, char **argv);
void			sort_stack_a(t_stack_node *stack_a);
void			free_stack(t_stack_node **stack);
void    		sorting_algorithm(t_stack_node **stack_a);


// Checking
void			error_message(void);
int				check_if_sorted(t_stack_node *stack);
t_stack_node    *find_last_node(t_stack_node *node);
t_stack_node	*create_int_list(char **argv, int size);



// Utils
int				find_stack_len(t_stack_node *stack);
int				find_min(t_stack_node *stack);
int				find_max(t_stack_node *stack);
int				find_median(t_stack_node *stack, int stack_len);


// Operations 
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

// TEMPORARY ////////////////////////////////////////////////////////////////////
void			printList(t_stack_node *head); ///////////// ------------------------------REMOVE

#endif 
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:21:47 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/11/21 20:26:44 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define ARG_MAX		1024

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
}	t_stack_node;

// Parsing input
t_stack_node	*process_argv(int argc, char **argv);
t_stack_node	*create_int_list(char **argv, int size);
int				check_for_duplicates(t_stack_node *stack_a);

// Sorting algorithms
void			sort_stack_a(t_stack_node **stack_a, t_stack_node **stack_b);
void			sort_three(t_stack_node **stack_a);
void			sort_five(t_stack_node **stack_a, t_stack_node **stack_b);
void			sort_four(t_stack_node **stack_a, t_stack_node **stack_b);
void			big_sort(t_stack_node **stack_a, t_stack_node **stack_b);

// BIG SORT
// Initialisation
void			current_index(t_stack_node *stack);
void			initialise_nodes_a(t_stack_node *stack_a,
					t_stack_node *stack_b);
void			initialise_nodes_b(t_stack_node *stack_a,
					t_stack_node *stack_b);
void			set_target_for_a(t_stack_node *stack_a, t_stack_node *stack_b);
void			set_target_for_b(t_stack_node *stack_a, t_stack_node *stack_b);
void			set_price(t_stack_node *stack_a, t_stack_node *stack_b);
void			set_cheapest_node(t_stack_node *stack_a);

// Checking
int				check_if_sorted(t_stack_node *stack);
t_stack_node	*find_last_node(t_stack_node *node);
int				find_stack_len(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*get_cheapest_node(t_stack_node *stack);

// Stack operations
bool			move_min_to_top(t_stack_node **stack_a);
void			align_for_push_a_to_b(t_stack_node **stack_a,
					t_stack_node **stack_b);
void			align_for_push_b_to_a(t_stack_node **stack_a,
					t_stack_node **stack_b);
void			swap_a(t_stack_node **stack_a);
void			swap_b(t_stack_node **stack_b);
void			swap_ab(t_stack_node **stack_a, t_stack_node **stack_b);
void			rotate_a(t_stack_node **stack_a);
void			rotate_b(t_stack_node **stack_b);
void			rotate_ab(t_stack_node **stack_a, t_stack_node **stack_b);
void			reverse_rotate_a(t_stack_node **stack_a);
void			reverse_rotate_b(t_stack_node **stack_b);
void			reverse_rotate_ab(t_stack_node **stack_a,
					t_stack_node **stack_b);
void			push_a(t_stack_node **stack_a, t_stack_node **stack_b);
void			push_b(t_stack_node **stack_b, t_stack_node **stack_a);

// Memory management and errors
void			free_array(char ***split_argv);
void			free_stack(t_stack_node **stack);
void			error_exit_all(char ***split_argv, t_stack_node **stack);
void			error_exit_stack(t_stack_node **stack);
void			error_exit(void);
void			error_exit_array(int argc, char **split_array);

#endif
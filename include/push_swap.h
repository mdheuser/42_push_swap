/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:21:47 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/11/07 17:37:02 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/////////////////////////////////////////////////////////////////////////////////////
# define DEBUG_MODE 0

# if DEBUG_MODE
#  define DEBUG_PRINT(fmt, args...) fprintf(stderr, fmt "\n", ## args)
# else
#  define DEBUG_PRINT(fmt, args...)
# endif
/////////////////////////////////////////////////////////////////////////////////////

# include "../libft/libft.h"
# include <unistd.h> // read(), write()
# include <stdlib.h> // malloc(), free(), exit()
# include <limits.h>
# include <stdio.h> // REMOVE -------------------------------------------------------------

# define ARG_MAX		1024 // ?????

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

// DEBUGGING

# if DEBUG_MODE
static inline void printList(t_stack_node *head)
{
	t_stack_node *tmp;
	
	tmp = head;
	printf("\n");
	while (tmp != NULL)
	{
		printf("%d", tmp->value);
		if (tmp->next != NULL)
			printf(" ");
		tmp = tmp->next;
	}
	printf("\n");
}
# endif

///TEMPORARY ////////////////////////////////////////////////////////////////////////
void bubble_sort_push_swap(t_stack_node **stack_a, t_stack_node **stack_b);


// Key functions
t_stack_node 	*process_argv(int argc, char **argv);
void			sort_stack_a(t_stack_node *stack_a, t_stack_node *stack_b);
void			free_stack(t_stack_node **stack);
void    		big_sort(t_stack_node **stack_a, t_stack_node **stack_b);
void			sort_three(t_stack_node **stack_a);
void    		sort_five(t_stack_node **stack_a, t_stack_node **stack_b);
void    		sort_four(t_stack_node **stack_a, t_stack_node **stack_b);
bool			move_min_to_top(t_stack_node **stack_a);


void			error_exit(t_stack_node *stack_a);
void			error_exit_array(int argc, char **split_array, int len);

// Checking
int				check_if_sorted(t_stack_node *stack);
t_stack_node    *find_last_node(t_stack_node *node);
t_stack_node	*create_int_list(char **argv, int size);
void			current_index(t_stack_node *stack);

// Utils
int				find_stack_len(t_stack_node *stack);
t_stack_node    *find_min(t_stack_node *stack);
t_stack_node    *find_max(t_stack_node *stack);
void			free_array(char **split_argv, int len);


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

#endif 
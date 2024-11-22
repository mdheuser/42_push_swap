/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 22:06:41 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/11/14 20:57:22 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void	from_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	align_for_push_a_to_b(stack_a, stack_b);
	push_b(stack_b, stack_a);
}

static void	from_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	align_for_push_b_to_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	set_target_for_b(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	while (stack_b)
	{
		best_match_index = LONG_MAX;
		target_node = NULL;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->value > stack_b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (target_node == NULL)
			stack_b->target_node = find_min(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

// Find `a` node's target in stack `b`
// The target has to be the closest smaller number/value in b
// closest smaller number to the current
// OR the maximum number
void	set_target_for_a(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_match_index;

	while (stack_a)
	{
		best_match_index = LONG_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->value < stack_a->value
				&& current_b->value > best_match_index)
			{
				best_match_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			stack_a->target_node = find_max(stack_b);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a->next;
	}
}

// Push two nodes to Stack B to initialise it.
// Calculate the cost of pushing from A to B and push nodes accordingly.
// When only 3 nodes are left in Stack A, sort it.
// Push back all nodes from B to A and place them in the right position.
// Move the node with the minimum value to the top of Stack A.
void	big_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	len_a;
	int	remaining_pushes;

	len_a = (find_stack_len(*stack_a));
	if (len_a-- > 3 && !check_if_sorted(*stack_a))
		push_b(stack_b, stack_a);
	if (len_a-- > 3 && !check_if_sorted(*stack_a))
		push_b(stack_b, stack_a);
	remaining_pushes = (find_stack_len(*stack_a) - 3);
	while (remaining_pushes > 0)
	{
		initialise_nodes_a(*stack_a, *stack_b);
		from_a_to_b(stack_a, stack_b);
		remaining_pushes--;
	}
	if (find_stack_len(*stack_a) == 3 && !check_if_sorted(*stack_a))
		sort_three(stack_a);
	while (*stack_b)
	{
		initialise_nodes_b(*stack_a, *stack_b);
		from_b_to_a(stack_a, stack_b);
	}
	current_index(*stack_a);
	move_min_to_top(stack_a);
}

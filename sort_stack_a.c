/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:59:10 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/11/14 22:04:21 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Moves smallest number to the top and checks if stack is sorted.
// Returns true if the stack becomes sorted in the while loop.
bool	move_min_to_top(t_stack_node **stack_a)
{
	t_stack_node	*min;

	min = find_min(*stack_a);
	current_index(*stack_a);
	while (*stack_a != min)
	{
		if (min->above_median)
			rotate_a(stack_a);
		else
			reverse_rotate_a(stack_a);
	}
	return (check_if_sorted(*stack_a));
}

void	sort_five(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (move_min_to_top(stack_a))
		return ;
	push_b(stack_b, stack_a);
	current_index(*stack_a);
	sort_four(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	sort_four(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (move_min_to_top(stack_a))
		return ;
	push_b(stack_b, stack_a);
	sort_three(stack_a);
	push_a(stack_a, stack_b);
}

void	sort_three(t_stack_node **stack_a)
{
	t_stack_node	*max;

	max = find_max(*stack_a);
	if (!max)
		return ;
	if ((*stack_a)->value == max->value)
		rotate_a(stack_a);
	else if ((*stack_a)->next->value == max->value)
		reverse_rotate_a(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap_a(stack_a);
}

// When Stack A is called here, it is NECESSARILY unsorted.
// That's why these IF statementes do not check for sortedness.
void	sort_stack_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	stack_len;

	stack_len = find_stack_len(*stack_a);
	if (stack_len == 2)
		swap_a(stack_a);
	else if (stack_len == 3)
		sort_three(stack_a);
	else if (stack_len == 4)
		sort_four(stack_a, stack_b);
	else if (stack_len == 5)
		sort_five(stack_a, stack_b);
	else if (stack_len > 5)
		big_sort(stack_a, stack_b);
}

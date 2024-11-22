/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:25:04 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/11/14 19:27:30 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Determines the cheapest node to push.
// If one or more nodes have the same price, the one with the lowest index
// is set as the cheapest.
void	set_cheapest_node(t_stack_node *stack)
{
	long			cheapest_value;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

// Finds the prices for each node before pushing from A to B.
void	set_price(t_stack_node *stack_a, t_stack_node *stack_b)
{
	int	stack_a_len;
	int	stack_b_len;

	stack_a_len = find_stack_len(stack_a);
	stack_b_len = find_stack_len(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->push_cost = stack_a_len - stack_a->index;
		if (stack_a->target_node->above_median)
			stack_a->push_cost += stack_a->target_node->index;
		else
			stack_a->push_cost += stack_b_len - (stack_a->target_node->index);
		stack_a = stack_a->next;
	}
}

void	initialise_nodes_a(t_stack_node *stack_a, t_stack_node *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_for_a(stack_a, stack_b);
	set_price(stack_a, stack_b);
	set_cheapest_node(stack_a);
}

void	initialise_nodes_b(t_stack_node *stack_a, t_stack_node *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_for_b(stack_a, stack_b);
}

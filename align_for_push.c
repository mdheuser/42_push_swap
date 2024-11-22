/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_for_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:29:20 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/11/14 21:49:28 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	align_for_push_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{	
	if (!(*stack_a) || !(*stack_b)->target_node || !(*stack_b))
		return ;
	while (*stack_b && (*stack_b)->target_node
		&& (*stack_b)->target_node != *stack_a)
	{
		if (*stack_b == NULL)
			break ;
		if ((*stack_b)->target_node == *stack_a)
			break ;
		if ((*stack_b)->target_node->above_median)
			rotate_a(stack_a);
		else
			reverse_rotate_a(stack_a);
	}
}

static void	finalise_alignment(t_stack_node **stack_a,
	t_stack_node **stack_b, t_stack_node *cheapest)
{
	while (*stack_a && *stack_a != cheapest)
	{
		if (cheapest->above_median)
			rotate_a(stack_a);
		else
			reverse_rotate_a(stack_a);
	}
	while (*stack_b && *stack_b != cheapest->target_node)
	{
		if (cheapest->target_node->above_median)
			rotate_b(stack_b);
		else
			reverse_rotate_b(stack_b);
	}
}

void	align_for_push_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest_node(*stack_a);
	if (!cheapest_node)
		return ;
	while (*stack_a != cheapest_node && *stack_b != cheapest_node->target_node)
	{
		if (cheapest_node->above_median
			&& cheapest_node->target_node->above_median)
			rotate_ab(stack_a, stack_b);
		else if (!cheapest_node->above_median
			&& !cheapest_node->target_node->above_median)
			reverse_rotate_ab(stack_a, stack_b);
		else
			break ;
	}
	finalise_alignment(stack_a, stack_b, cheapest_node);
}

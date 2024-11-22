/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 20:34:53 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/11/14 19:09:03 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*second_to_last_node;
	t_stack_node	*last_node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	second_to_last_node = NULL;
	last_node = *stack;
	while (last_node->next)
	{
		second_to_last_node = last_node;
		last_node = last_node->next;
	}
	second_to_last_node->next = NULL;
	last_node->next = *stack;
	(*stack)->prev = last_node;
	last_node->prev = NULL;
	*stack = last_node;
	current_index(*stack);
}

void	reverse_rotate_a(t_stack_node **stack_a)
{
	ft_printf("rra\n");
	reverse_rotate(stack_a);
}

void	reverse_rotate_b(t_stack_node **stack_b)
{
	ft_printf("rrb\n");
	reverse_rotate(stack_b);
}

void	reverse_rotate_ab(t_stack_node **stack_a, t_stack_node **stack_b)
{
	ft_printf("rrr\n");
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}

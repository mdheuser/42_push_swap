/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:04:20 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/11/14 19:10:04 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*first_node;
	t_stack_node	*last_node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first_node = *stack;
	last_node = find_last_node(*stack);
	*stack = first_node->next;
	first_node->next = NULL;
	last_node->next = first_node;
	current_index(*stack);
}

void	rotate_a(t_stack_node **stack_a)
{
	ft_printf("ra\n");
	rotate(stack_a);
}

void	rotate_b(t_stack_node **stack_b)
{
	ft_printf("rb\n");
	rotate(stack_b);
}

void	rotate_ab(t_stack_node **stack_a, t_stack_node **stack_b)
{
	ft_printf("rr\n");
	rotate(stack_a);
	rotate(stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:05:20 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/11/14 19:10:45 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_stack_node **stack)
{
	int	swap;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	swap = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = swap;
	current_index(*stack);
}

void	swap_a(t_stack_node **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_stack_node **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	swap_ab(t_stack_node **stack_a, t_stack_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}

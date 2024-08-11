/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:05:20 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/08/11 20:11:02 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// function prototype

// FIRST a swap function.

// THEN SA, SB and SS

#include "push_swap.h"

static void    swap_any(t_stack_node **node)
{
	int	swap;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
        return ;
	swap = (*node)->value;
	(*node)->value = (*node)->next->value;
	(*node)->next->value = swap;
}

void    swap_a(t_stack_node **stack_a)
{
	swap_any(stack_a);
	write(1, "sa\n", 3);
}

void    swap_b(t_stack_node **stack_b)
{
	swap_any(stack_b);
	write(1, "sb\n", 3);
}

void	swap_ab(t_stack_node **stack_a, t_stack_node **stack_b)
{
	swap_any(stack_a);
	swap_any(stack_b);
	write(1, "ss\n", 3);
}


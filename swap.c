/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:05:20 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/08/08 20:55:09 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// function prototype

// FIRST a swap function.

// THEN SA, SB and SS

#include "push_swap.h"

static t_stack_node    *swap_ab(t_stack_node *node)
{
	int swap;
	
	swap = node->value;
	node->value = node->next->value;
	node->next->value = swap;
	return (node);
}

t_stack_node    *swap_a(t_stack_node *node)
{
	swap_ab(node);
	write(1, "sa\n", 3);
	return (node);
}

t_stack_node    *swap_b(t_stack_node *node)
{
	swap_ab(node);
	write(1, "sb\n", 3);
	return (node);
}


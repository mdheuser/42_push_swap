/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 22:13:16 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/11/14 19:07:56 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*node_to_move;

	if (*src == NULL)
		return ;
	node_to_move = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_move->prev = NULL;
	if (*dest == NULL)
	{
		*dest = node_to_move;
		node_to_move->next = NULL;
	}
	else
	{
		node_to_move->next = *dest;
		(*dest)->prev = node_to_move;
		*dest = node_to_move;
	}
	current_index(*src);
	current_index(*dest);
}

// Pushes from stack b to stack a.
void	push_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
}

// Pushes from stack a to stack b.
void	push_b(t_stack_node **stack_b, t_stack_node **stack_a)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
}

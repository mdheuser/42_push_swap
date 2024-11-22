/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:12:23 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/11/14 20:34:25 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	find_stack_len(t_stack_node *stack)
{
	t_stack_node	*tmp;
	int				stack_len;

	stack_len = 0;
	tmp = stack;
	while (tmp)
	{
		stack_len++;
		tmp = tmp->next;
	}
	return (stack_len);
}

int	check_if_sorted(t_stack_node *stack)
{
	t_stack_node	*current;

	current = stack;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

t_stack_node	*find_last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

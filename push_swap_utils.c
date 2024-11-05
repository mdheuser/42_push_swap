/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:12:23 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/11/05 11:16:58 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;

	if (!stack)
		return ;
	while(*stack)
	{
		tmp = (*stack)->next;
		(*stack)->value = 0;
		free(*stack);
		*stack = tmp;
	}
}

void    error_exit(t_stack_node **stack_a)
{
	if (stack_a)
		free_stack(stack_a);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int find_stack_len(t_stack_node *stack)
{
	t_stack_node    *tmp;
	int             stack_len;
	
	stack_len = 0;
	tmp = stack;
	while (tmp)
	{
		stack_len++;
		tmp = tmp->next; 
	}
	return (stack_len);
}

int check_if_sorted(t_stack_node *stack)
{
	while(stack && stack->next)
	{
		if(stack->value > stack->next->value)
		{
			DEBUG_PRINT("\nThe list is NOT sorted\n");
			return(0);
		}
		stack = stack->next;
	}
	DEBUG_PRINT("\nThe list is already in the right order\n");
	return (1);
}

t_stack_node    *find_last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while(stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

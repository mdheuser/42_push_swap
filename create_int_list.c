/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_int_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:06:19 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/11/05 15:18:45 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//This function converts the strings in argv into  integers.
// AND checks for duplicates
t_stack_node    *create_int_list(char **split_argv, int len)
{
	t_stack_node    *head;
	t_stack_node    *current;
	t_stack_node    *new_node;
	int             i;
	long			n;

	head = NULL;
	current = NULL;
	i = 0;
	while (i < len)
	{
		new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
		if (new_node == NULL)
			return (NULL);
		n = ft_atol(split_argv[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			DEBUG_PRINT("\n(overflow or underflow)\n");
			return (NULL);
		}
		new_node->value = n;
		new_node->next = NULL;
		if (head == NULL)
		{
			head = new_node;
			current = head;
		}
		else
		{
			current->next = new_node;
			current = new_node;
		}
		i++;
	}
	return (head);
}

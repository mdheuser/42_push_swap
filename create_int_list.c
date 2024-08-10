/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_int_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:06:19 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/08/10 21:46:29 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node    *create_int_list(char **split_argv, int size) // ??????????????????????????????
{
	t_stack_node    *head;
	t_stack_node    *current;
	t_stack_node    *new_node;
	int             i;

	head = NULL;
	current = NULL;
	i = 0;
	while (i < size)
	{
		new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
		if (new_node == NULL)
			return (NULL);
		new_node->value = ft_atoi(split_argv[i]);
		//printf("new_node->value: %d\n", new_node->value); ////// REMOVE ////////////////////////////////////////
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

///////////////////////////////////////////////////////////////////// DELETE /////////////////////

void printList(t_stack_node *head)
{
	t_stack_node *tmp;
	
	tmp = head;
	printf("stack_a:\n");
	while (tmp != NULL)
	{
		printf("%d ", tmp->value);
		if (tmp->next != NULL)
			printf(" -> ");
		tmp = tmp->next;
	}
	printf("\n");
}
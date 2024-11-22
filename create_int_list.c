/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_int_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:06:19 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/11/21 20:28:33 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Allocates memory for each node and returns it.
static t_stack_node	*create_node(long value)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->cheapest = false;
	new_node->above_median = false;
	new_node->next = NULL;
	return (new_node);
}

static bool	is_valid_number_length(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 11)
		return (false);
	return (true);
}

static int	is_valid_number(char *str)
{
	long long	n;

	if (!is_valid_number_length(str))
		return (0);
	n = ft_atol(str);
	if (n > INT_MAX || n < INT_MIN)
		return (0);
	return (1);
}

//This function converts the strings in argv into integers.
// It checks for INT_MAX and INT_MIN
// AND creates the nodes of Stack A.
t_stack_node	*create_int_list(char **split_argv, int len)
{
	t_stack_node	*head;
	t_stack_node	*current;
	t_stack_node	*new_node;
	int				i;
	long long		n;

	head = NULL;
	current = NULL;
	i = -1;
	while (++i < len)
	{
		if (!is_valid_number(split_argv[i]))
			error_exit_all(&split_argv, &head);
		n = ft_atol(split_argv[i]);
		new_node = create_node(n);
		if (!new_node)
			error_exit_stack(&head);
		if (!head)
			head = new_node;
		else
			current->next = new_node;
		current = new_node;
	}
	return (head);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:39:57 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/11/21 19:58:52 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Checks for characters that are not allowed
// and for - and + in strange positions.
static int	parse_array(char **split_argv, int len)
{
	int		i;
	int		j;
	char	c;
	char	next;

	if (!split_argv || len <= 0)
		return (0);
	i = -1;
	while (++i < len)
	{
		if (!split_argv[i] || split_argv[i][0] == '\0')
			return (0);
		j = -1;
		while (split_argv[i][++j])
		{
			c = split_argv[i][j];
			next = split_argv[i][j + 1];
			if ((ft_isdigit(c) == 0 && c != '-' && c != '+')
				|| (j > 0 && (c == '-' || c == '+'))
				|| ((c == '-' || c == '+') && next == '\0')
				|| ((c == '+' || c == '-') && (next == '+' || next == '-')))
				return (0);
		}
	}
	return (1);
}

// Checks for duplicated integers by traversing Stack A.
// (This function fixes a previous issue where numbers 
// such as 3 and 003 would not be detected as duplicates).
int	check_for_duplicates(t_stack_node *stack_a)
{
	t_stack_node	*current;
	t_stack_node	*runner;

	current = stack_a;
	while (current != NULL)
	{
		runner = current->next;
		while (runner)
		{
			if (current->value == runner->value)
				return (0);
			runner = runner->next;
		}
		current = current->next;
	}
	return (1);
}

// this function
// (1) checks for errors in argv,
// (2) converts it into a stack of ints.
// (3) checks for duplicated numbers.
// (4) Frees the array after Stack A is created.
// (5) returns Stack A in its initial unsorted form.
t_stack_node	*process_argv(int argc, char **argv)
{
	char			**split_argv;
	int				len;
	t_stack_node	*stack_a;

	stack_a = NULL;
	if (argc == 2)
	{
		split_argv = ft_split(argv[1], ' ');
		if (!split_argv || (!(*split_argv)))
			error_exit_array(argc, split_argv);
	}
	else
		split_argv = argv + 1;
	len = 0;
	while (split_argv[len] != NULL)
		len++;
	if (!parse_array(split_argv, len) || len > ARG_MAX)
		error_exit_array(argc, split_argv);
	stack_a = create_int_list(split_argv, len);
	if (!stack_a)
		error_exit_array(argc, split_argv);
	if (argc == 2)
		free_array(&split_argv);
	return (stack_a);
}

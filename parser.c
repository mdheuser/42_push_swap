/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:39:57 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/11/07 17:49:34 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Add error case where a number preceded by zero is also considered. 
// Example 3 03 should return error.
//

#include "include/push_swap.h"

static int	parse_array(char **split_argv, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (split_argv[i][j] != '\0')
		{
			if (ft_isdigit(split_argv[i][j]) == 0
			&& split_argv[i][j] != '-' && split_argv[i][j] != '+')
			{
				DEBUG_PRINT("non-digit character found\n");
				return (0);
			}
			if ((split_argv[i][j] == '-' || split_argv[i][j] == '+')
				&& (ft_isdigit(split_argv[i][j - 1]) == 1))
			{
				DEBUG_PRINT("- or + in the wrong position\n");
				return (0);
			}
			if ((split_argv[i][j] == '-' || split_argv[i][j] == '+')
			&& (split_argv[i][j + 1] == '\0'))
			{
				DEBUG_PRINT("- or + in the wrong position\n");
				return (0);
			}
			if ((split_argv[i][j] == '+' || split_argv[i][j + 1] == '-')
				&& (split_argv[i][j] == '+' || split_argv[i][j + 1] == '-'))
			{
				DEBUG_PRINT("-- OR ++ OR -+ OR +- \n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	free_array(char **split_argv, int len)
{
	int	i;

	if (split_argv == NULL)
		return ;
	i = 0;
	while (i < len)
	{
		free(split_argv[i]);
		i++;
	}
	free(split_argv);
}

// Checks for duplicated integers by traversing Stack A.
// (This function fixes a previous issue where numbers 
// such as 3 and 003 would not be detected as duplicates).
static int	check_for_duplicates(t_stack_node *stack_a)
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
			{	
				DEBUG_PRINT("Duplicates found");
				return (0);
			}
			runner = runner->next;
		}
		current = current->next;
	}
	return (1);
}

// this function
// (1) checks for errors in argv,
// (2) converts it into a stack of ints and
// (3) checks for duplicated ints.
// (4) Frees the array (if memory was allocated for it)
//     after Stack A is created.
// (5) returns Stack A
t_stack_node	*process_argv(int argc, char **argv)
{
	char			**split_argv;
	int				len;
	t_stack_node	*stack_a;

	stack_a = NULL;
	if (argc == 2)
		split_argv = ft_split(argv[1], ' ');
	else
		split_argv = argv + 1;
	len = 0;
	while (split_argv[len] != NULL)
		len++;
	if (!parse_array(split_argv, len))
		error_exit_array(argc, split_argv, len);
	stack_a = create_int_list(split_argv, len);
	if (!stack_a)
		error_exit_array(argc, split_argv, len);
	if (argc == 2)
		free_array(split_argv, len);
	if (!check_for_duplicates(stack_a))
		error_exit(stack_a);
	return (stack_a);
}

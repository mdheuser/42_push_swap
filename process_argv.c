/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:39:57 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/08/13 19:22:18 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

static int	check_duplicates(char **split_argv, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(split_argv[i], split_argv[j]) == 0)
			{
				printf("Duplicates found\n"); // -------------------------------------------------- REMOVE
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
static int	parse_array(char **split_argv, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (split_argv[i][j] != '\0')
		{
			if (ft_isdigit(split_argv[i][j]) == 0
			&& split_argv[i][j] != '-' && split_argv[i][j] != '+')
			{
				printf("non-digit character found\n");
				return (0);
			}
			else if ((split_argv[i][j] == '-' || split_argv[i][j] == '+')
			&& (ft_isdigit(split_argv[i][j - 1]) == 1))
			{
				printf("- or + in the wrong position\n");
				return (0);
			}
			else if ((split_argv[i][j] == '-' || split_argv[i][j] == '+')
			&& (split_argv[i][j + 1] == '\0'))
			{
				printf("- or + in the wrong position\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	if (check_duplicates(split_argv, size) == 0)
		return (0);
	return (1);
}

static void free_array(char **split_argv, int len)
{
    int i;

    if (split_argv == NULL)
        return ; // Check if the array is NULL
    // Free each inner array (row) using a while loop
    i = 0;
    while (i < len) {
        free(split_argv[i]); // Free the current row
        i++; // Increment the index
    }
    // Free the outer array
    free(split_argv);
}

// this function checks for errors in argv, converts it into a stack and returns it or NULL.
t_stack_node    *process_argv(int argc, char **argv)
{
    char            **split_argv;
    int             len;
    t_stack_node    *stack_a;
	
    if (argc == 1)
		return (NULL);
	if (argc == 2)
	{	
		printf("argc == 2: %s\n\n", argv[1]);
		split_argv = ft_split(argv[1], ' ');
	}
	else
		split_argv = argv + 1;
	len = 0;
	while (split_argv[len] != NULL)
		len++;
	if (parse_array(split_argv, len) == 0)
	{
		printf("Parsing error");
		//error_message();
		if (argc == 2)
			free_array(split_argv, len);
		return (NULL);
	}
	printf("\nnumber counter: %d\n\n", len); ////////////////////////////////////// REMOVE
	stack_a = create_int_list(split_argv, len);
    if (stack_a == NULL)
	{
		//error_message();
		printf("stack_a is NULL\n"); /////////////////////////////////// REMOVE
		if (argc == 2)
			free_array(split_argv, len);
		return (NULL);
	}
    if (argc == 2)
		free_array(split_argv, len);
    return (stack_a);
}
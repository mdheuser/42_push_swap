/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:30:43 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/08/11 22:00:00 by mdahlstr         ###   ########.fr       */
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
int	parse_array(char **split_argv, int size)
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
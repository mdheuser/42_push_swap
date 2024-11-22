/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_and_memory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:33:38 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/11/21 20:26:27 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	free_array(char ***split_argv)
{
	int	i;

	if (split_argv == NULL || *split_argv == NULL)
		return ;
	i = 0;
	while ((*split_argv)[i] != NULL)
	{
		free((*split_argv)[i]);
		i++;
	}
	free(*split_argv);
	*split_argv = NULL;
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	error_exit_all(char ***split_argv, t_stack_node **stack)
{
	free_array(split_argv);
	free_stack(stack);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	error_exit_stack(t_stack_node **stack)
{
	if (stack && *stack)
		free_stack(stack);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	error_exit_array(int argc, char **split_array)
{
	if (argc == 2)
		free_array(&split_array);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

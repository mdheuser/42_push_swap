/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:21:49 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/11/21 20:23:45 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	if (argc == 1)
		return (EXIT_SUCCESS);
	if ((argc > 1 && argv[1][0] == '\0') || (argc - 1) > ARG_MAX)
		error_exit();
	stack_a = process_argv(argc, argv);
	if (!stack_a)
		return (EXIT_FAILURE);
	stack_b = NULL;
	if (!check_for_duplicates(stack_a))
		error_exit_stack(&stack_a);
	if (!check_if_sorted(stack_a))
		sort_stack_a(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (EXIT_SUCCESS);
}

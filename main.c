/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:21:49 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/11/07 16:02:28 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TO DO LIST
// Handle error in which 03 and 3 should be detected as duplicates.

#include "include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = process_argv(argc, argv);
	if (!stack_a)
		error_exit(NULL);
	stack_b = NULL;
	#if DEBUG_MODE
		printList(stack_a);
	#endif
	//DEBUG_PRINT("\nMIN = %d\n", find_min(stack_a));
	//DEBUG_PRINT("\nMAX = %d\n", find_max(stack_a));
	if (find_stack_len(stack_a) == 1)
	{
		free_stack(&stack_a);
		return (0);
	}
	if (!check_if_sorted(stack_a))
		sort_stack_a(stack_a, stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

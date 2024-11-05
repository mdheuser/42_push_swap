/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                            :+:      :+:    :+:    */ 
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:21:49 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/07/26 13:21:50 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TO DO LIST
// Handle error in which 03 and 3 should be detected as duplicates.


/*In case of error, it must display "Error" followed by a ’\n’ on the standard error.
Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer and/or there are duplicates.*/

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack_node    *stack_a;
	t_stack_node	*stack_b;

	stack_a = process_argv(argc, argv);
	stack_b = NULL;
	if (!stack_a)
		error_exit(stack_a);
	#if DEBUG_MODE
	printList(stack_a);
	#endif
	DEBUG_PRINT("\nMIN = %d\n", find_min(stack_a));
	DEBUG_PRINT("\nMAX = %d\n", find_max(stack_a));
	if (!check_if_sorted(stack_a))
		sort_stack_a(stack_a, stack_b);
	free_stack(&stack_a);
	return (0);
}
//
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

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack_node    *stack_a;
	t_stack_node    *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	
	stack_a = process_argv(argc, argv);
	if (!stack_a)
		return (0);
	////////////
	printList(stack_a); //////////////////////////////////// REMOVE ---------------------
	///////////////////
	sort_stack_a(stack_a);

	//////// TESTING CREATION OF STACK_B AND PUSHING ///////////////////////////////////////
	//push_b(&stack_b, &stack_a);
	//push_b(&stack_b, &stack_a);
	//printf("\nStack b:\n");
	//printList(stack_b);
	//printf("Stack b size: %d", ft_lstsize(**stack_b));
	//printf("\nStack a after pushing to b:\n");
	//printList(stack_a);
	//printf("Stack a size: %d", ft_lstsize(*stack_a));
	////////////////////////////////////////
	if (stack_b)
		free(stack_b); // NOT LIKE THIS // CREATE a function that frees stacks.
	return (0);
}
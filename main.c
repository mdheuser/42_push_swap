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
	int             len;
	char            **split_argv;

	stack_a = NULL;
	stack_b = NULL;
	// turn all this section into a separate function that checks for errors, 
	// turns argv into split_argv when necessary AND converts it into a linked list.
	// "process_argv" 
	if (argc == 1)
		return (0);
	// stack_a = process_argv(argc, argv);
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
			free(split_argv);
		return (0);
	}
	printf("\nnumber counter: %d\n\n", len); ////////////////////////////////////// REMOVE
	stack_a = create_int_list(split_argv, len);
	/// (process_argv) UNTIL HERE?
	printList(stack_a); //////////////////////////////////// REMOVE ---------------------
	if (stack_a == NULL)
	{
		//error_message();
		printf("stack_a is NULL\n"); /////////////////////////////////// REMOVE
		if (argc == 2)
			free(split_argv);
		return (0);
	}
	// THEN A line where stack_a is sorted
	// sort_stack_a -> should deal with all cases.
	if (len == 2)
		sort_two_numbers(&stack_a);
	else if (len == 3)
		sort_three_numbers(&stack_a);
	else if (len > 3)
	{
		check_if_sorted(stack_a);
		//sorting_algorithm(&stack_a, len);
	}
	//////// TESTING CREATION OF STACK_B AND PUSHING ///////////////////////////////////////
	push_b(&stack_b, &stack_a);
	push_b(&stack_b, &stack_a);
	printf("\nStack b:\n");
	printList(stack_b);
	//printf("Stack b size: %d", ft_lstsize(**stack_b));
	printf("\nStack a after pushing to b:\n");
	printList(stack_a);
	//printf("Stack a size: %d", ft_lstsize(*stack_a));
	////////////////////////////////////////
	if (argc == 2)
		free(split_argv);
	if (len > 3)
		free(stack_b); // NOT LIKE THIS // CREATE a function that frees stacks.
	return (0);
}
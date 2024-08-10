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
	//t_stack_node    *stack_b;
	int             len;
	char            **split_argv;

	stack_a = NULL;
	//stack_b = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{	
		printf("argc == 2: %s\n\n", argv[1]);
		split_argv = ft_split(argv[1], ' ');
		printf("\n\n%s, %s, %s\n\n", split_argv[0], split_argv[1], split_argv[2]); // OK!
	}
	else
	{
		split_argv = argv + 1;
		printf("%s, %s, %s\n\n", split_argv[0], split_argv[1], split_argv[2]); // OK!
	}
	len = 0;
	while (split_argv[len] != NULL) // this funcion establishes the size of the array.
	{
		//printf("\n\nSplit_argv in all cases HERE:\n%s\n", split_argv[len]); // TO DO ------------------------------------------
		len++;
	}
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
	printList(stack_a); //////////////////////////////////// REMOVE ---------------------
	if (stack_a == NULL)
	{
		//error_message();
		printf("stack_a is NULL\n"); ///////////////////////////////////
		if (argc == 2)
			free(split_argv);
		return (0);
	}
	
	if (argc == 2)
		free(split_argv);
	return (0);
}
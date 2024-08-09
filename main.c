/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   TO DO */ 
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
	int             i;
	char            **split_argv;

	stack_a = NULL;
	//stack_b = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
		split_argv = ft_split(argv[1], ' ');
	else
		split_argv = argv + 1;
	i = 0;
	while (split_argv[i] != NULL)
	{
		//printf("\n\nHERE:\n%s\n", argv[i]); // TO DO ------------------------------------------
		i++;
	}
	if (parse_array(split_argv, i) == 0)
	{
		error_message();
		if (argc == 2)
			free(split_argv);
		return (0);
	}
	printf("\ncount of strings: %d\n\n", i); ////////////////////////////////////// REMOVE
	stack_a = create_int_list(split_argv, i);
	if (stack_a == NULL)
	{
		error_message();
		write(1, "stack_a is NULL", 15); ///////////////////////////////////
		if (argc == 2)
			free(split_argv);
		return (0);
	}
	printList(stack_a); //////////////////////////////////// REMOVE ---------------------
	if (argc == 2)
		free(split_argv);
	return (0);
}
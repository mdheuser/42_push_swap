/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:59:10 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/08/13 17:07:03 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    sort_two_numbers(t_stack_node **stack_a)
{
    if(check_if_sorted(*stack_a) == 0)
        swap_a(stack_a);
    else
        return ;
    //free stack_a ???????
    printf("\nSorted stack: \n"); /////////////////////////////REMOVE
    printList(*stack_a); ///////////////////////////////////////////REMOVE
}

static void    sort_three_numbers(t_stack_node **stack_a)
{
    int a;
    int b;
    int c;

    if (check_if_sorted(*stack_a) == 1)
        return ;
    a = (*stack_a)->value;
    b = (*stack_a)->next->value;
    c = (*stack_a)->next->next->value;
    if (a > b && b > c) // 3 2 1
    {
        swap_a(stack_a);
        reverse_rotate_a(stack_a);
    }
    else if (a > c && c > b) // 3 1 2
        rotate_a(stack_a);
    else if (b > a && a > c) // 2 3 1
        reverse_rotate_a(stack_a);
    else if (b > c && c > a) // 1 3 2
    {
        swap_a(stack_a);
        rotate_a(stack_a);
    }
    else if (c > a && a > b) // 2 1 3
        swap_a(stack_a);
    printf("\nSorted stack: \n"); /////////////////////////////REMOVE
    printList(*stack_a); ///////////////////////////////////////////REMOVE
}

//sorting_algorithm
/*void    sorting_algorithm(t_stack_node **stack_a)
{
    while (stack_a)
    {
        if ((*stack_a)->value > (*stack_a)->next->value)
            swap_a(*stack_a);
    }
}*/

void    sort_stack_a(t_stack_node *stack_a)
{
    int stack_len;

    stack_len = find_stack_len(stack_a);
    printf("\nstack_len: %d", stack_len);
    if (stack_len == 2)
		sort_two_numbers(&stack_a);
	else if (stack_len == 3)
		sort_three_numbers(&stack_a);
	else if (stack_len > 3)
	{
		check_if_sorted(stack_a);
		//sorting_algorithm(&stack_a, len);
        // sort long lists
	}
}
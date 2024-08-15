/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:59:10 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/08/15 11:58:10 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    sort_three_numbers(t_stack_node **stack_a)
{   
    if (find_max(*stack_a) == (*stack_a)->value)
        rotate_a(stack_a);
    else if (find_max(*stack_a) == (*stack_a)->next->value)
        reverse_rotate_a(stack_a);
    if ((*stack_a)->value > (*stack_a)->next->value)
        swap_a(stack_a);
    printf("\nSorted stack: \n"); /////////////////////////////REMOVE
    printList(*stack_a); ///////////////////////////////////////////REMOVE
}

void    sort_stack_a(t_stack_node *stack_a)
{
    int stack_len;

    stack_len = find_stack_len(stack_a);
    printf("\nstack_len: %d", stack_len);
    if (stack_len == 2)
    {
		swap_a(&stack_a);
        printf("\nSorted stack: \n"); /////////////////////////////REMOVE
        printList(stack_a); ///////////////////////////////////////////REMOVE
    }
    else if (stack_len == 3)
		sort_three_numbers(&stack_a);
	else if (stack_len > 3)
		sorting_algorithm(&stack_a);
}
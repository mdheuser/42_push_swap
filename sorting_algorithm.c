/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 22:06:41 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/11/05 10:38:48 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Push elements from stack_a to stack_b one by one, until only 3 numbers
	are left in stack_a.

	For each push, the number from stack_a should be pushed to the right postion
	in stack_b. 
    
    So, before pushing, we need to calculate the cost of pushing each element
	in stack_a to stack_b, to find the cheapest element which using least operations.
*/
void    sort_till_3(t_stack_node *stack_a, t_stack_node *stack_b)
{
    (void)stack_a;
    (void)stack_b;
}

void    sorting_algorithm(t_stack_node **stack_a, t_stack_node **stack_b)
{
    int len_a;

    len_a = (find_stack_len(*stack_a));
    if (len_a-- > 3 && !check_if_sorted(*stack_a))
        push_b(stack_b, stack_a);
    if (len_a-- > 3 && !check_if_sorted(*stack_a))
        push_b(stack_b, stack_a);
    while (len_a-- > 3 && !check_if_sorted(*stack_a))
    {
        /* init_nodes_a() - WHAT IS THIS?
        sets current index of a and b
        set the targets
        cost analysis
        set cheapest
        */
        sort_till_3(*stack_a, *stack_b);
    }
    sort_three_numbers(stack_a);
    
    
    
    #if DEBUG_MODE
    printList(*stack_a);
    printList(*stack_b);
    #endif
    // if not sorted
        // sort 3
}
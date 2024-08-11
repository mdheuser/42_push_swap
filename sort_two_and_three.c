/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_and_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 20:57:17 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/08/11 20:57:21 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_two_numbers(t_stack_node **stack_a)
{
    if(check_if_sorted(*stack_a) == 0)
        swap_a(stack_a);
    else
        return ;
    //free stack_a ???????
    printf("\nSorted stack: \n"); /////////////////////////////REMOVE
    printList(*stack_a); ///////////////////////////////////////////REMOVE
}

void    sort_three_numbers(t_stack_node **stack_a)
{
    int a;
    int b;
    int c;

    if (check_if_sorted(*stack_a) == 0)
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
    else if (c > a && a > b)
        swap_a(stack_a);
    printf("\nSortet stack: \n"); /////////////////////////////REMOVE
    printList(*stack_a); ///////////////////////////////////////////REMOVE
}
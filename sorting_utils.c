/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:30:30 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/08/15 16:18:41 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    find_min(t_stack_node *stack)
{
    int i;

    i = stack->value;
    while (stack)
    {
        if (stack->value < i)
            i = stack->value;
        stack = stack->next;
    }
    return (i);
}

int    find_max(t_stack_node *stack)
{
    int i;

    i = stack->value;
    while (stack)
    {
        if (stack->value > i)
            i = stack->value;
        stack = stack->next;
    }
    return (i);
}

int find_median(t_stack_node *stack, int stack_len)
{
    t_stack_node    *current;
    int             median;
    int             median_index;
    int             i;

    current = NULL;
    median = 0;
    median_index = 0;
    i = 0;

    if (stack_len % 2 == 0)
        median_index = (stack_len / 2) - 1;
    else 
        median_index = (stack_len / 2);
    printf("\nMedian_index: %d\n", median_index);
    while (i <= median_index)
    {
        median = stack->value;
        i++;
        current = current->next;
    }
    return (median);
}
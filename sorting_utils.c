/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:30:30 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/11/04 20:27:07 by mdahlstr         ###   ########.fr       */
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
    int             median_index;
    int             i;

    current = stack;
    median_index = (stack_len / 2);
    i = 0;

    DEBUG_PRINT("\nMedian_index: %d\n", median_index);
    while (current && i < median_index)
    {
        current = current->next;
        i++;
    }

    if (current)
        return (current->value);
    else
        return (0);
}

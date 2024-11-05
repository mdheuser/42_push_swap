/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:30:30 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/11/05 10:33:05 by mdahlstr         ###   ########.fr       */
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
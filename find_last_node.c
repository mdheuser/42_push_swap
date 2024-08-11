/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_last_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:10:48 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/08/11 19:26:01 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node    *find_last_node(t_stack_node *stack)
{
    if (!stack)
        return (NULL);
    while(stack->next)
    {
        stack = stack->next;
    }
    return (stack);
}

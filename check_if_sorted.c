/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:13:23 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/08/11 20:22:37 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_if_sorted(t_stack_node *stack)
{
    while(stack && stack->next)
    {
        if(stack->value > stack->next->value)
        {
            printf("\nThe list is NOT sorted\n"); // REMOVE ----------------------------
            return(0);
        }
        stack = stack->next;
    }
    printf("\nThe list is already in the right order\n"); // REMOVE --------------------
    return (1);
}
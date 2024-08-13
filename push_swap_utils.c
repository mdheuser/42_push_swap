/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:12:23 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/08/13 17:09:36 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    error_message(void)
{
	write(1, "Error\n", 6);
}

int find_stack_len(t_stack_node *stack)
{
    t_stack_node    *tmp;
    int             stack_len;
    
    stack_len = 0;
    tmp = stack;
    while (tmp)
    {
        stack_len++;
        tmp = tmp->next; 
    }
    return (stack_len);
}

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


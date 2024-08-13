/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 20:34:53 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/08/13 16:53:47 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void    reverse_rotate(t_stack_node **stack)
{
    t_stack_node    *second_to_last_node;
    t_stack_node    *last_node;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    
    second_to_last_node = NULL;
    last_node = *stack;
    
    while (last_node->next)
    {
        second_to_last_node = last_node;
        last_node = last_node->next;
    }

    second_to_last_node->next = NULL;

    last_node->next = *stack;
    *stack = last_node;
}

void    reverse_rotate_a(t_stack_node **stack_a)
{
    write(1, "rra\n", 4);
    reverse_rotate(stack_a);
    
}

void    reverse_rotate_b(t_stack_node **stack_b)
{
    write(1, "rrb\n", 4);
    reverse_rotate(stack_b);
}

void    reverse_rotate_ab(t_stack_node **stack_a, t_stack_node **stack_b)
{
    write(1, "rrr\n", 4);
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
}

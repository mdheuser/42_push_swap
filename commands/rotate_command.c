/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:04:20 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/08/13 16:53:52 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void    rotate(t_stack_node **stack)
{
    t_stack_node    *first_node;
    t_stack_node    *last_node;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    first_node = *stack;
    last_node = find_last_node(*stack);
    
    *stack = first_node->next;
    first_node->next = NULL;
    last_node->next = first_node;
}

void    rotate_a(t_stack_node **stack_a)
{
    write(1, "ra\n", 3);
    rotate(stack_a);
    
}

void    rotate_b(t_stack_node **stack_b)
{
    write(1, "rb\n", 3);
    rotate(stack_b);
}

void    rotate_ab(t_stack_node **stack_a, t_stack_node **stack_b)
{
    write(1, "rr\n", 3);
    rotate(stack_a);
    rotate(stack_b);
}

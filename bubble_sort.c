/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:51:21 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/11/07 13:47:52 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static int check_if_sorted_inv(t_stack_node *stack)
{
    while(stack && stack->next)
	{
		if(stack->value < stack->next->value)
		{
			//DEBUG_PRINT("\nThe list is NOT sorted in descending order\n");
			return(0);
		}
		stack = stack->next;
	}
	//DEBUG_PRINT("\nThe list is already in the right DESCENDING order\n");
	return (1);    
}

static bool	move_max_to_top(t_stack_node **stack_b)
{
    t_stack_node *max;
	
	max = find_max(*stack_b);
    current_index(*stack_b);
    while (*stack_b != max)
    {
        if (!max->above_median)
            rotate_b(stack_b);
        else
            reverse_rotate_b(stack_b);
		if (check_if_sorted_inv(*stack_b))
            return (true);
	}
	return (false);
}

void bubble_sort_push_swap(t_stack_node **stack_a, t_stack_node **stack_b)
{
    int len = find_stack_len(*stack_a);
    int sorted = 0;

    while (!sorted)
    {
        sorted = 1;
        int i = 0;
        while (i < len - 1)
        {
            // Compare top two elements of stack_a
            if ((*stack_a)->value > (*stack_a)->next->value)
            {
                swap_a(stack_a);
                sorted = 0;
            }
            // Move top element to stack_b
            push_b(stack_b, stack_a);
            if (find_stack_len(*stack_b) >= 2)
            {
                if ((*stack_b)->value < (*stack_b)->next->value)
                    swap_b(stack_b);
            }
            if (move_min_to_top(stack_a))
                break ;
            move_max_to_top(stack_b);
            i++;
        }

        // Move last element to stack_b
        push_b(stack_a, stack_b);

        // Move all elements back to stack_a
        while (*stack_b)
        {
            push_a(stack_a, stack_b);
        }
        len--;
    }
    #if DEBUG_MODE
	DEBUG_PRINT("Stack a:\n");
	printList(*stack_a);
	DEBUG_PRINT("Stack b:\n");
	printList(*stack_b);
	#endif
}
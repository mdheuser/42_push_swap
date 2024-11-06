/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:59:10 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/11/06 21:31:25 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// MAYBE CREATE A FUNCTION THAT MOVES MIN TO TOP.
/*
void	move_min_to_top(t_stack_node **stack_a)
{
    t_stack_node *min;  // Find the minimum node
	
	min = find_min(*stack_a);  // Find the minimum node
    current_index(*stack_a);  // Update indices if needed
    // Loop until `min` is at the top of stack_a
    while (*stack_a != min)
    {
        if (min->above_median)
            rotate_a(stack_a);  // Rotate towards the top if `min` is closer to the bottom
        else
            reverse_rotate_a(stack_a);  // Reverse rotate if `min` is closer to the top
    }
}
*/

void    sort_five(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*min;

	min = find_min(*stack_a);
	current_index(*stack_a);
	// move_min_to_top()
	while (*stack_a != min)
	{
		if (min->above_median)
			rotate_a(stack_a);
		else
			reverse_rotate_a(stack_a);
		if (check_if_sorted(*stack_a))
			return ;
	}
	push_b(stack_b, stack_a);
	current_index(*stack_a);
	sort_four(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void    sort_four(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*min;
	//move min to top()
	min = find_min(*stack_a);
	current_index(*stack_a);
	while (*stack_a != min)
	{
		if (min->above_median)
			rotate_a(stack_a);
		else
			reverse_rotate_a(stack_a);
		if (check_if_sorted(*stack_a))
			return ;
	}	
	push_b(stack_b, stack_a);
	sort_three(stack_a);
	push_a(stack_a, stack_b);
}

void    sort_three(t_stack_node **stack_a)
{	
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && b < c && a < c)
		swap_a(stack_a);
	else if (a > b && b > c)
	{
  		swap_a(stack_a);
		reverse_rotate_a(stack_a);
  	}
  	else if (a > b && b < c && a > c)
		rotate_a(stack_a);
  	else if (a < b && b > c && a < c)
  	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if (a < b && b > c && a > c)
		reverse_rotate_a(stack_a);
}

void    sort_stack_a(t_stack_node *stack_a, t_stack_node *stack_b)
{
	int stack_len;

	stack_len = find_stack_len(stack_a);
	DEBUG_PRINT("\nstack_len: %d", stack_len);
	if (stack_len == 2)
	{
		DEBUG_PRINT("\nSorted stack of 2: \n");
		swap_a(&stack_a);
		#if DEBUG_MODE
		printList(stack_a);
		#endif
	}
	else if (stack_len == 3)
	{
		DEBUG_PRINT("\nSorted stack of 3: \n");
		sort_three(&stack_a);
		#if DEBUG_MODE
  		printList(stack_a);
  		#endif
	}
	else if (stack_len == 4)
	{
		DEBUG_PRINT("\nSorted stack of 4: \n");
		sort_four(&stack_a, &stack_b);
		#if DEBUG_MODE
  		printList(stack_a);
  		#endif
	}
	else if (stack_len == 5)
	{
		DEBUG_PRINT("\nSorted stack of 5: \n");
		sort_five(&stack_a, &stack_b);
		#if DEBUG_MODE
  		printList(stack_a);
  		#endif
	}
	else if (stack_len > 5)
		big_sort(&stack_a, &stack_b);
}

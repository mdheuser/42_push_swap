/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 22:06:41 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/11/06 19:11:04 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

//Find `a` node's target in stack `b`
// The target has to be the closest smaller number/value in b
// closest smaller number to the current
// OR the maximum number
static void	set_target_for_a(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_match_index;

	while (stack_a)
	{
		best_match_index = LONG_MIN;
		current_b = stack_b;
		while (stack_b)
		{
			if (current_b->value < stack_a->value
				&& current_b->value > best_match_index)
			{
				best_match_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			stack_a->target_node = find_max(stack_b);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a->next;
		DEBUG_PRINT("stack a: %d: target: %d",
			stack_a->value, stack_a->target_node->value);
	}
}

// Sets the index of every value in the stack
// (a or b depending on which one is called)
// Sets above_median to true or false.
void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = find_stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i < median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	initialise_nodes_a(t_stack_node *stack_a, t_stack_node *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_for_a(stack_a, stack_b);
	// cost analysis for pushing from a to b.
	// set cheapest from a to b. ????
}

/*
	Push elements from stack_a to stack_b one by one, until only 3 numbers
	are left in stack_a.

	For each push, the number from stack_a should be pushed to the right postion
	in stack_b. 
	
	So, before pushing, we need to calculate the cost of pushing each element
	in stack_a to stack_b, to find the cheapest element which using least
	operations.
*/
void	sort_till_3(t_stack_node *stack_a, t_stack_node *stack_b)
{
	(void)stack_a;
	(void)stack_b;
}

void	big_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	len_a;

	len_a = (find_stack_len(*stack_a));
	if (len_a-- > 3 && !check_if_sorted(*stack_a))
		push_b(stack_b, stack_a);
	if (len_a-- > 3 && !check_if_sorted(*stack_a))
		push_b(stack_b, stack_a);
	//while (len_a-- > 3 && !check_if_sorted(*stack_a))
	//{
		/* init_nodes_a() - WHAT IS THIS?
		sets current index of a and b
		set the targets
		cost analysis
		set cheapest
		*/
		//sort_till_3(*stack_a, *stack_b);
	//}
	if (len_a == 3)
		sort_three(stack_a);
	#if DEBUG_MODE
	DEBUG_PRINT("Stack a:\n");
	printList(*stack_a);
	DEBUG_PRINT("Stack b:\n");
	printList(*stack_b);
	#endif
	// if not sorted
		// sort 3
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 22:06:41 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/08/15 15:25:41 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sorting_algorithm(t_stack_node **stack_a)
{
    t_stack_node    *stack_b;
    t_stack_node    *current;
    int median;
    int stack_a_len;
    int i;

    stack_b = NULL;
    current = *stack_a;
    stack_a_len = find_stack_len(*stack_a);
    median = find_median(*stack_a, stack_a_len);
   
    i = 0;
    //////////// CHECKS //////////////
    printf("\nMedian: %d\n", median);
    printf("\nStack_a_len: %d\n", stack_a_len);
    printf("\nStack_a_len divided by 2: %d\n", stack_a_len / 2);
    /////////////////////////
    
    while (i < (stack_a_len / 2))
    {
        if (current->value >= median)
            push_b(&stack_b, stack_a);
        else
            rotate_a(stack_a);
        i++;
    }
    
    /*
    while (i < (stack_a_len))
    {
        push_b(&stack_b, stack_a);
        current  = current->next;
    }
    */
    printf("\nStack A: \n");
    printList(*stack_a);
    printf("\nStack B: \n");
    printList(stack_b);
}
    // transfer elements larger than median to stack b. ??

    

/*
SOURCE: https://www.youtube.com/watch?v=MiIWv3CwHSk 

The algorithm aims to sort data efficiently using two piles, 
named pile A and pile B. Here is a detailed explanation of the 
sorting steps: 

Step 1️⃣: Identify the Median and 
Initial Distribution Objective: Find the median of the values 
​​in pile A. Action: Transfer the elements from pile A to pile B. 
The elements larger than the median are placed on top of pile B, 
while the smaller ones are placed below.

Step 2️⃣: Pre-Sort in 
Pile B Objective: Organize pile B more finely to facilitate the 
final sorting. Action: Continue to move the elements from pile 
A to pile B. This step ensures that the elements larger than the 
median remain on top in pile B and the smaller ones below. 

Step 3️⃣: Finalization of the Sorting and Repatriation in Stack A 
Objective: Final sorting and optimization of the placement of the 
elements. Action: Bring all the elements from stack B to stack A. 
At each transfer, the algorithm evaluates the most efficient method 
to insert the element into stack A, minimizing the number of 
operations required. 🔔 For more information or for specific questions: 
@toukoum on Discord. 💻 The code for this algorithm is available on 
GitHub: https://github.com/toukoum/push_swap-42 . 
*/
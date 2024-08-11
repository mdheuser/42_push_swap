#include "push_swap.h"

void    sort_two_numbers(t_stack_node **stack_a)
{
    if(check_if_sorted(*stack_a) == 0)
        swap_a(*stack_a);
    else 
        free(stack_a);
    printf("\nSortet stack: \n"); /////////////////////////////REMOVE
    printList(*stack_a); ///////////////////////////////////////////REMOVE
}

/*
void    sort_three_numbers(t_stack_node **stack_a)
{
    int a;
    int b;
    int c;

    a = (*stack_a)->value;
    b = (*stack_a)->next->value;
    c = (*stack_a)->next->next->value;
    if (check_if_sorted(*stack_a) == 0)
        return ;
    else if (a < c && c < b) // 1 3 2
        swap_a(*stack_a);
    printf("\nSortet stack: \n"); /////////////////////////////REMOVE
    printList(*stack_a); ///////////////////////////////////////////REMOVE
}
*/
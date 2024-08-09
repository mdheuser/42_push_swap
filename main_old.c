/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:52:48 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/07/24 18:54:34 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack_node    *node_a;
    //t_stack_node    *node_b;
    t_stack_node    *node_value; // NOT SURE HOW TO NAME THIS
    int             i;
    int             number;
    
    node_a = NULL;
    //node_b = NULL;
    i = 1;
    // if there is only one argument OR if there are only two arguments and argv[1][0] is null. (return 1)
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
    //Else if: Split argv and convert each number into a node.
    else if (argc == 2)
        argv = ft_split(argv[1], ' ');
    // assign values to nodes
    while (argv[i] != NULL)
    {
        number = ft_atoi(argv[i]);
        node_value = malloc(sizeof(t_stack_node));
        if (node_a == NULL)
        {
            return (1); // AND Free memory thus far
        }
        node_value->value = number;
        node_value->next = node_a;
        node_a = node_value;
        i++;
    }
    // print whole list:
    t_stack_node    *ptr = node_a;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->value);
        ptr = ptr->next;
    }
    // swap values if there are only two nodes + the first is bigger than the second 
    if (i == 3 && node_a->value > node_a->next->value)
        swap_a(node_a);
    return (0);
}

/*
INPUT : ONE String OR a Variable number of arguments

COMMANDS :

sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.

sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.

ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.

rrr : rra and rrb at the same time.


*/
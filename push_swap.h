/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:21:47 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/08/11 18:35:33 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//ft_printf and any equivalent YOU coded

# include "libft/libft.h"
# include <unistd.h> // read(), write()
# include <stdlib.h> // malloc(), free(), exit()
# include <limits.h>
# include <stdio.h> // REMOVE -------------------------------------------------------------
# include <stdbool.h>

typedef struct s_stack_node
{
	int					value;
	int					position;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
} t_stack_node;

int				main(int argc, char **argv);

// Checking
int				parse_array(char **argv, int size);
int				check_if_sorted(t_stack_node *stack);



void			error_message(void);
t_stack_node	*create_int_list(char **argv, int size);


t_stack_node	*swap_a(t_stack_node *node);
t_stack_node	*swap_b(t_stack_node *node);

void			printList(t_stack_node *head); ///////////// ------------------------------REMOVE

// Sorting
void    sort_two_numbers(t_stack_node **stack_a);
void    sort_three_numbers(t_stack_node **stack_a);



#endif 
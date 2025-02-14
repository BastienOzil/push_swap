/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:21:37 by bozil             #+#    #+#             */
/*   Updated: 2025/01/29 10:21:37 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
#include <limits.h>

typedef struct s_node
{
    int value;
    struct s_node *next;
} t_node;

/*Parsing*/
t_node  *parse_args(char **argv);

/*Swap*/
void    swap(t_node **stack);
void    sa(t_node **stack_a);
void    sb(t_node **stack_b);
void    ss(t_node **stack_a, t_node **stack_b);

/*Push*/
void    push(t_node **src, t_node **dst);
void    pa(t_node **stack_a, t_node **stack_b);
void    pb(t_node **stack_a, t_node **stack_b);

/*Rotate*/
void    rotate(t_node **stack);
void    ra(t_node **stack_a);
void    rb(t_node **stack_b);
void    rr(t_node **stack_a, t_node **stack_b);

/*Reverse Rotate*/
void    reverse_rotate(t_node **stack);
void    rra(t_node **stack_a);
void    rrb(t_node **stack_b);
void    rrr(t_node **stack_a, t_node **stack_b);

/* Sort */
void sort_stack(t_node **stack_a, t_node **stack_b);
int stack_size(t_node *stack);
void sort_two(t_node **stack_a);
void sort_three(t_node **stack_a);
void sort_five(t_node **stack_a, t_node **stack_b);
void sort_large(t_node **stack_a, t_node **stack_b);

/*Utils*/
void    print_error(void);

#endif

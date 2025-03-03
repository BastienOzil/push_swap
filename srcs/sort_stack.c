/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:29:48 by bozil             #+#    #+#             */
/*   Updated: 2025/01/29 11:29:48 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sort_stack(t_node **stack_a, t_node **stack_b)
{
    int size = stack_size(*stack_a);

    if (size == 2)
        sort_two(stack_a);
    else if (size == 3)
        sort_three(stack_a);
    else if (size == 5)
        sort_five(stack_a, stack_b);
    else
        sort_large(stack_a, stack_b);
}

void sort_two(t_node **stack_a)
{
    if ((*stack_a)->value > (*stack_a)->next->value)
        sa(stack_a);
}

void sort_three(t_node **stack_a)
{
    int a = (*stack_a)->value;
    int b = (*stack_a)->next->value;
    int c = (*stack_a)->next->next->value;

    if (a > b && b < c && a < c)
        sa(stack_a);
    else if (a > b && b > c)
    {
        sa(stack_a);
        rra(stack_a);
    }
    else if (a > b && b < c && a > c)
        ra(stack_a);
    else if (a < b && b > c && a < c)
    {
        sa(stack_a);
        ra(stack_a);
    }
    else if (a < b && b > c && a > c)
        rra(stack_a);
}

void sort_five(t_node **stack_a, t_node **stack_b)
{
    while (stack_size(*stack_a) > 3)
    {
        int min_index = find_min_index(*stack_a);
        move_to_top(stack_a, min_index);
        pb(stack_a, stack_b);
    }
    sort_three(stack_a);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
}

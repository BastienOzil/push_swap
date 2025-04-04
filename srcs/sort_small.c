/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:13:18 by bozil             #+#    #+#             */
/*   Updated: 2025/04/04 12:14:11 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    push_min_elements(t_node **stack_a, t_node **stack_b, int count)
{
    int i;
    int min_index;
    
    i = 0;
    while (i < count && !is_sorted(*stack_a))
    {
        min_index = find_min_index(*stack_a);
        move_to_top(stack_a, min_index);
        pb(stack_a, stack_b);
        i++;
    }
}

void    push_back_all(t_node **stack_a, t_node **stack_b, int count)
{
    int i;
    
    i = 0;
    while (i < count && *stack_b)
    {
        pa(stack_a, stack_b);
        i++;
    }
}

void    sort_small_insertion(t_node **stack_a, t_node **stack_b, int size)
{
    if (is_sorted(*stack_a))
        return;
    
    push_min_elements(stack_a, stack_b, size);
    push_back_all(stack_a, stack_b, size);
}

void    optimize_push_to_b(t_node **stack_a, t_node **stack_b, int bit)
{
    int size;
    int i;
    int push_count;
    int to_push;
    
    size = stack_size(*stack_a);
    to_push = count_pushable_bits(*stack_a, bit, size);
    
    if (to_push == 0 || to_push == size)
        return;
    
    i = 0;
    push_count = 0;
    while (i < size)
    {
        if ((((*stack_a)->value >> bit) & 1) == 0)
        {
            pb(stack_a, stack_b);
            push_count++;
        }
        else
            ra(stack_a);
        i++;
    }
    
    push_back_all(stack_a, stack_b, push_count);
}

int    should_use_insertion(int size)
{
    return (size <= 20);
}

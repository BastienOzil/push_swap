/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:10:13 by bozil             #+#    #+#             */
/*   Updated: 2025/04/04 12:15:04 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    move_stack_b(t_node **stack_a, t_node **stack_b, int bit)
{
    optimize_push_to_b(stack_a, stack_b, bit);
}

void    normalize(t_node *stack)
{
    optimize_normalize(stack);
}

void    sort_large(t_node **stack_a, t_node **stack_b)
{
    int size;
    int max_bits;
    int bit;
    
    if (is_sorted(*stack_a))
        return;
    
    size = stack_size(*stack_a);
    if (should_use_insertion(size))
    {
        sort_small_insertion(stack_a, stack_b, size);
        return;
    }
    
    normalize(*stack_a);
    max_bits = calc_max_bits(size);
    
    bit = 0;
    while (bit < max_bits)
    {
        if (!is_sorted(*stack_a))
            move_stack_b(stack_a, stack_b, bit);
        bit++;
    }
}

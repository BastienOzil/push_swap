/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:10:13 by bozil             #+#    #+#             */
/*   Updated: 2025/03/04 10:14:30 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void push_lower_bits(t_node **stack_a, t_node **stack_b, int bit)
{
    int size = stack_size(*stack_a);
    int i = 0;

    while (i < size)
    {
        if ((((*stack_a)->value >> bit) & 1) == 0)
            pb(stack_a, stack_b);
        else
            ra(stack_a);
        i++;
    }
}

void sort_large(t_node **stack_a, t_node **stack_b)
{
    int max_bits;
    int bit;
    int size = stack_size(*stack_a);
    int i;

    if (is_sorted(*stack_a))
        return;

    max_bits = 0;
    while ((size >> max_bits) != 0)
        max_bits++;

    bit = 0;
    while (bit < max_bits)
    {
        i = 0;
        while (i < size)
        {
            if ((((*stack_a)->value >> bit) & 1) == 0)
                pb(stack_a, stack_b);
            else
                ra(stack_a);
            i++;
        }

        while (*stack_b)
            pa(stack_a, stack_b);

        bit++;
    }
}


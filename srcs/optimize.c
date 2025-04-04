/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:12:09 by bozil             #+#    #+#             */
/*   Updated: 2025/04/04 12:12:55 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    fill_sorted_array(t_node *stack, int *arr)
{
    int i;
    
    i = 0;
    while (stack)
    {
        arr[i] = stack->value;
        stack = stack->next;
        i++;
    }
}

void    rank_values(t_node *stack, int *sorted, int size)
{
    int i;
    t_node *current;
    
    current = stack;
    while (current)
    {
        i = 0;
        while (i < size)
        {
            if (current->value == sorted[i])
            {
                current->value = i;
                break;
            }
            i++;
        }
        current = current->next;
    }
}

void    optimize_normalize(t_node *stack)
{
    int *sorted;
    int size;
    
    size = stack_size(stack);
    sorted = malloc(size * sizeof(int));
    if (!sorted)
        return;
    
    fill_sorted_array(stack, sorted);
    sort_array(sorted, size);
    rank_values(stack, sorted, size);
    
    free(sorted);
}

int    calc_max_bits(int size)
{
    int bits;
    
    bits = 0;
    while ((size >> bits) != 0)
        bits++;
    return (bits);
}
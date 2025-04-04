/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:10:32 by bozil             #+#    #+#             */
/*   Updated: 2025/04/04 12:10:50 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    swap_ints(int *a, int *b)
{
    int temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}

int    partition(int *arr, int low, int high)
{
    int pivot;
    int i;
    int j;
    
    pivot = arr[high];
    i = low - 1;
    j = low;
    
    while (j <= high - 1)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap_ints(&arr[i], &arr[j]);
        }
        j++;
    }
    swap_ints(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void    quick_sort_recursive(int *arr, int low, int high)
{
    int pi;
    
    if (low < high)
    {
        pi = partition(arr, low, high);
        quick_sort_recursive(arr, low, pi - 1);
        quick_sort_recursive(arr, pi + 1, high);
    }
}

void    sort_array(int *arr, int size)
{
    quick_sort_recursive(arr, 0, size - 1);
}

int    count_pushable_bits(t_node *stack, int bit, int size)
{
    int count;
    int i;
    
    count = 0;
    i = 0;
    while (stack && i < size)
    {
        if (((stack->value >> bit) & 1) == 0)
            count++;
        stack = stack->next;
        i++;
    }
    return (count);
}

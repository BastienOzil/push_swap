/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:10:13 by bozil             #+#    #+#             */
/*   Updated: 2025/03/28 14:53:59 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_stack_b(t_node **stack_a, t_node **stack_b, int bit)
{
	int	size;
	int	current_size;
	int	pushed_count;

	size = stack_size(*stack_a);
	current_size = size;
	pushed_count = 0;
	while (current_size > 0)
	{
		if ((((*stack_a)->value >> bit) & 1) == 0)
		{
			pb(stack_a, stack_b);
			pushed_count++;
		}
		else
			ra(stack_a);
		current_size--;
	}
	while (pushed_count > 0)
	{
		pa(stack_a, stack_b);
		pushed_count--;
	}
}

void	rank_stack(t_node *stack, int *sorted, int size)
{
	t_node	*current;
	int		i;

	current = stack;
	while (current)
	{
		i = -1;
		while (++i < size)
		{
			if (current->value == sorted[i])
			{
				current->value = i;
				break ;
			}
		}
		current = current->next;
	}
}

void	bubble_sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	normalize(t_node *stack)
{
	int	*sorted;
	int	size;
	int	i;

	size = stack_size(stack);
	sorted = malloc(size * sizeof(int));
	if (!sorted)
		return ;
	i = -1;
	while (++i < size)
	{
		sorted[i] = stack_get_at_index(stack, i);
	}
	bubble_sort_array(sorted, size);
	rank_stack(stack, sorted, size);
	free(sorted);
}

void	sort_large(t_node **stack_a, t_node **stack_b)
{
	int	max_bits;
	int	bit;

	if (is_sorted(*stack_a))
		return ;
	normalize(*stack_a);
	max_bits = 0;
	while ((stack_size(*stack_a) >> max_bits) != 0)
		max_bits++;
	bit = 0;
	while (bit < max_bits)
	{
		move_stack_b(stack_a, stack_b, bit);
		bit++;
	}
}

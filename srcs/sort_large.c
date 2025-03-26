/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:10:13 by bozil             #+#    #+#             */
/*   Updated: 2025/03/25 12:39:34 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	move_stack_b(t_node **stack_a, t_node **stack_b, int bit)
{
	int	size;
	int	pushed_count;
	int	i;

	size = stack_size(*stack_a);
	pushed_count = 0;
	i = 0;
	while (i < size)
	{
		if ((((*stack_a)->value >> bit) & 1) == 0)
		{
			pb(stack_a, stack_b);
			pushed_count++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (pushed_count > 0)
	{
		pa(stack_a, stack_b);
		pushed_count--;
	}
}

void	sort_large(t_node **stack_a, t_node **stack_b)
{
	int	max_bits;
	int	bit;

	if (is_sorted(*stack_a))
		return ;
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

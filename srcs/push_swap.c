/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:38:35 by bozil             #+#    #+#             */
/*   Updated: 2025/03/31 16:38:35 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min(t_node *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

void	shift_stack(t_node *stack)
{
	int	min;

	min = find_min(stack);
	while (stack)
	{
		stack->value -= min;
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc < 2)
		return (1);
	if (argc == 2)
		stack_a = handle_single_arg(argv[1]);
	else
		stack_a = handle_multiple_args(argv + 1);
	if (!stack_a)
		print_error();
	start_sorting(&stack_a, &stack_b);
	return (0);
}

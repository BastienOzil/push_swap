/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:42:47 by bozil             #+#    #+#             */
/*   Updated: 2025/03/17 13:42:47 by bozil            ###   ########.fr       */
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
	char	**split_argv;

	if (argc < 2)
		return (1);
	if (argc == 2)
	{
		if (!is_valid_input(argv[1]))
			print_error();
		split_argv = split_args(argv[1]);
		stack_a = parse_args(split_argv, split_argv);
		free_split(split_argv);
	}
	else
	{
		stack_a = parse_args(argv + 1, NULL);
	}
	if (!stack_a)
		print_error();
	stack_b = NULL;
	shift_stack(stack_a);
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}

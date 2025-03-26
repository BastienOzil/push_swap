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

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**split_argv;

	if (argc < 2)
	{
		write(1, "Usage: ./push_swap numbers\n", 27);
		return (1);
	}
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
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}

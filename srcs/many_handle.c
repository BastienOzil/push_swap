/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:33:15 by bozil             #+#    #+#             */
/*   Updated: 2025/04/04 11:39:10 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*handle_single_arg(char *arg)
{
	char	**split_argv;
	t_node	*stack_a;

	if (!is_valid_input(arg))
		print_error();
	split_argv = split_args(arg);
	if (!split_argv)
		print_error();
	stack_a = parse_args(split_argv, split_argv);
	if (!stack_a)
		print_error_and_free(NULL, split_argv);
	free_split(split_argv);
	return (stack_a);
}

t_node	*handle_multiple_args(char **args)
{
	if (!are_valid_args(args))
		print_error();
	return (parse_args(args, NULL));
}

void start_sorting(t_node **stack_a, t_node **stack_b)
{
    *stack_b = NULL;

    shift_stack(*stack_a);
    sort_stack(stack_a, stack_b);
    free_stack(stack_a);
    if (*stack_b)
        free_stack(stack_b);
}

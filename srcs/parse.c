/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:42:56 by bozil             #+#    #+#             */
/*   Updated: 2025/03/17 13:42:56 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**split_args(char *arg)
{
	char	**args;

	args = ft_split(arg, ' ');
	if (!args || !args[0])
		print_error_and_free(NULL, args);
	return (args);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

t_node	*parse_args(char **argv, char **split_argv)
{
	t_node	*stack;
	t_node	*tail;
	t_node	*new;
	long	num;

	stack = NULL;
	tail = NULL;
	while (*argv)
	{
		num = ft_atol(*argv, split_argv);
		if (num > INT_MAX || num < INT_MIN)
			print_error_and_free(&stack, split_argv);
		
		if (is_duplicate(stack, (int)num))
			print_error_and_free(&stack, split_argv);
		
		new = create_new_node((int)num, &stack, split_argv);
		if (!stack)
			stack = new;
		else
			tail->next = new;
		tail = new;
		argv++;
	}
	return (stack);
}

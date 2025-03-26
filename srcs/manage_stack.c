/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:11:41 by bozil             #+#    #+#             */
/*   Updated: 2025/03/26 18:14:50 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	print_error_and_free(t_node **stack, char **split_argv)
{
	if (stack && *stack)
	{
		free_stack(stack);
		*stack = NULL;
	}
	if (split_argv)
	{
		free_split(split_argv);
	}
	write(2, "Error\n", 6);
	exit(1);
}

t_node	*create_new_node(int num, t_node **stack, char **split_argv)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
	{
		if (stack && *stack)
			free_stack(stack);
		if (split_argv)
			free_split(split_argv);
		print_error();
	}
	new->value = num;
	new->next = NULL;
	return (new);
}

void	free_stack(t_node **stack)
{
	t_node   *head;
	t_node   *tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	*stack = NULL;
}

void	print_stack(t_node *stack, char *name)
{
	ft_printf("%s: ", name);
	while (stack)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}
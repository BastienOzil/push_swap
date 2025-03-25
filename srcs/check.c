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

void	print_error(void)
{
	write(2, "Error\n", 6);
	
	exit(1);
}

static long	ft_atol(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	if (*str < '0' || *str > '9')
		print_error();
	while (*str >= '0' && *str <= '9')
	{
		if ((num > (INT_MAX / 10)) || 
		    (num == (INT_MAX / 10) && (*str - '0') > (INT_MAX % 10)))
			print_error();
		num = num * 10 + (*str - '0');
		str++;
	}
	if (*str != '\0')
		print_error();
	return (num * sign);
}


static int	is_duplicate(t_node *head, int num)
{
	while (head)
	{
		if (head->value == num)
			return (1);
		head = head->next;
	}
	return (0);
}

static t_node	*create_new_node(int num, t_node **stack)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
	{
		free_stack(stack);
		print_error();
	}
	new->value = num;
	new->next = NULL;
	return (new);
}

t_node	*parse_args(char **argv)
{
	t_node	*stack;
	t_node	*tail;
	t_node	*new;
	int		num;

	stack = NULL;
	tail = NULL;
	while (*argv)
	{
		num = ft_atol(*argv);
		if (is_duplicate(stack, num))
		{
			free_stack(&stack);
			print_error();
		}
		new = create_new_node(num, &stack);
		if (!stack)
			stack = new;
		else
			tail->next = new;
		tail = new;
		argv++;
	}
	return (stack);
}



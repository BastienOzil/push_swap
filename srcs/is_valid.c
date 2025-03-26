/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:10:00 by bozil             #+#    #+#             */
/*   Updated: 2025/03/27 00:09:31 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_valid_input(char *arg)
{
	int	i;
	int	has_digit;

	i = 0;
	has_digit = 0;
	while (arg[i])
	{
		if (!(arg[i] == ' ' || (arg[i] >= '0' && arg[i] <= '9') || 
			  arg[i] == '+' || arg[i] == '-'))
			return (0);
		if ((arg[i] == '+' || arg[i] == '-') &&
			(i > 0 && arg[i - 1] != ' '))
			return (0);
		if (arg[i] >= '0' && arg[i] <= '9')
			has_digit = 1;
		i++;
	}
	return (has_digit);
}

long	ft_atol(const char *str, char **split_argv)
{
	long	num;
	int		sign;
	int		digits;

	num = 0;
	sign = 1;
	digits = 0;
	while (*str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		if (digits > 10 || 
			(num > LONG_MAX / 10) || 
			(num == LONG_MAX / 10 && (*str - '0') > LONG_MAX % 10))
		{
			if (split_argv)
				free_split(split_argv);
		}
		num = num * 10 + (*str - '0');
		str++;
		digits++;
	}
	while (*str == ' ')
		str++;
	if (*str != '\0')
	{
		if (split_argv)
			free_split(split_argv);
		num = 1000000000000000000;
	}
	return (num * sign);
}

int	is_duplicate(t_node *head, int num)
{
	while (head)
	{
		if (head->value == num)
			return (1);
		head = head->next;
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:10:00 by bozil             #+#    #+#             */
/*   Updated: 2025/04/04 12:08:47 by bozil            ###   ########.fr       */
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
		if (!(arg[i] == ' ' || (arg[i] >= '0' && arg[i] <= '9') || arg[i] == '+'
				|| arg[i] == '-'))
			return (0);
		if ((arg[i] == '+' || arg[i] == '-') && (!arg[i + 1]
				|| !(arg[i + 1] >= '0' && arg[i + 1] <= '9')))
			return (0);
		if (arg[i] >= '0' && arg[i] <= '9')
			has_digit = 1;
		i++;
	}
	return (has_digit);
}

long	ft_atol(const char *str, char **split_argv)
{
	int		sign;
	long	num;

	sign = get_sign(&str);
	num = convert_to_long(&str, split_argv);
	return (num * sign);
}

int	get_sign(const char **str)
{
	int	sign;

	sign = 1;
	while (**str == ' ')
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

void check_end_of_number(const char **str, char **split_argv)
{
    if (**str != '\0' && **str != ' ' && **str != '\t')
    {
        if (split_argv)
            print_error_and_free(NULL, split_argv);
        else
            print_error();
    }
}

long convert_to_long(const char **str, char **split_argv)
{
    long num;
    int  digits;

    num = 0;
    digits = 0;
    while (**str >= '0' && **str <= '9')
    {
        if (digits > 10 || num > LONG_MAX / 10 || (num == LONG_MAX / 10
                && (**str - '0') > LONG_MAX % 10))
        {
            if (split_argv)
                print_error_and_free(NULL, split_argv);
            else
                print_error();
        }
        num = num * 10 + (**str - '0');
        (*str)++;
        digits++;
    }
    check_end_of_number(str, split_argv);
    return (num);
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

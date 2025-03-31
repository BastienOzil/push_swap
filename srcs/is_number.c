/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:26:07 by bozil             #+#    #+#             */
/*   Updated: 2025/03/31 15:26:18 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_number(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	are_valid_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!is_number(args[i]))
			return (0);
		i++;
	}
	return (1);
}

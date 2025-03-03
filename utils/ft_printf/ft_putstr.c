/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:43:10 by bozil             #+#    #+#             */
/*   Updated: 2024/11/23 11:03:17 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	if (str == NULL)
	{
		c += write(1, "(null)", 6);
		return (c);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (ft_strlen(str));
}

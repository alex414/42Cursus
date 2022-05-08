/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:17:36 by adiaz-do          #+#    #+#             */
/*   Updated: 2022/04/09 20:52:28 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Kant.h"

int	ft_onephilo(void)
{
	printf("%s", "0 ms Philo 1 Left fork  \n");
	printf("%s", "0 ms Philo 1 Die alone 🥺 \n");
	return (1);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_isspace(const char str)
{
	if (str == ' ' || str == '\n' || str == '\t'
		|| str == '\v' || str == '\f' || str == '\r')
		return (1);
	return (0);
}

int	ft_atoi_parser(const char *str)
{
	long	num;

	num = 0;
	while (*str && ft_isspace(*str))
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			return (1);
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		num = num * 10 + *str - 48;
		if (num > INT_MAX)
			return (0);
		if (num < INT_MIN)
			return (0);
		str++;
	}
	return (num);
}

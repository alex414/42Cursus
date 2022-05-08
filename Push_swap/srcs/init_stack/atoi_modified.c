/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_modified.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:37:01 by adiaz-do          #+#    #+#             */
/*   Updated: 2021/11/01 20:37:02 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_push_swap.h"

int	ft_atoi_modified(const char *str)
{
	long	num;
	int		neg;

	num = 0;
	neg = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
	{
		if (!ft_isalnum(str[1]))
			error();
		str++;
	}
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - 48);
		str++;
	}
	if (((*str < '0' || *str > '9') && *str) || num > 2147483647
		|| num < -2147483648)
		error();
	return ((int)(num * neg));
}

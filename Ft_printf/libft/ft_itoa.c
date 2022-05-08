/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:22:20 by adiaz-do          #+#    #+#             */
/*   Updated: 2020/11/19 20:22:21 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_intlen(int n)
{
	long	nbr;
	int		len;

	len = 0;
	nbr = n;
	if (nbr < 0)
	{
		len++;
		nbr = nbr * (-1);
	}
	while (nbr / 10 != 0)
	{
		len++;
		nbr /= 10;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	int		c;
	char	*toreturn;
	int		nbr;
	int		isneg;

	nbr = n;
	isneg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if ((toreturn = (char*)ft_calloc(sizeof(char), (ft_intlen(n) + 1))) == NULL)
		return (NULL);
	if (nbr < 0)
	{
		toreturn[0] = '-';
		nbr = nbr * (-1);
		isneg = 1;
	}
	c = ft_intlen(nbr) - !isneg;
	while (c >= isneg)
	{
		toreturn[c] = nbr % 10 + '0';
		nbr /= 10;
		c -= 1;
	}
	return (toreturn);
}

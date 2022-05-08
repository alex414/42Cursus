/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:23:21 by adiaz-do          #+#    #+#             */
/*   Updated: 2020/11/19 20:23:23 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		num;
	char	print;

	if (n == -2147483648)
	{
		write(fd, "-2", 2);
		num = 147483648;
	}
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			num = n * (-1);
		}
		else
			num = n;
	}
	if (num / 10 != 0)
		ft_putnbr_fd(num / 10, fd);
	print = (num % 10) + 48;
	write(fd, &print, 1);
}

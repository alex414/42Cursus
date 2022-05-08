/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unintype.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:20:46 by adiaz-do          #+#    #+#             */
/*   Updated: 2020/11/19 20:20:47 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			get_tens(unsigned int num)
{
	unsigned int tens;

	tens = 1;
	while ((num /= 10) > 0)
		tens++;
	return (tens);
}

void				ft_putuns_fd(unsigned int nb, int fd)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = (unsigned int)(nb * -1);
	}
	else
		nbr = (unsigned int)nb;
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd((char)(nbr % 10 + 48), fd);
}

static t_t			*logic_u(t_t *t, unsigned int num, int length, int flag)
{
	int			not_blank;

	not_blank = length;
	if (length <= t->pres)
		not_blank = t->pres;
	t->rv += (not_blank <= t->width) ? t->width : not_blank;
	if (!flag && (t->conver[2] != '0' || t->pres >= 0))
		print_aux(t, ' ', t->width - not_blank, 0);
	if (t->conver[2] == '0' && t->pres < 0)
		print_aux(t, '0', t->width - not_blank, 0);
	print_aux(t, '0', t->pres - length, 0);
	ft_putuns_fd(num, 1);
	if (flag)
		print_aux(t, ' ', t->width - not_blank, 0);
	return (t);
}

t_t					*uninttype(t_t *t)
{
	int				length;
	int				flag;
	unsigned int	num;

	flag = 0;
	num = (unsigned int)(va_arg(t->ap, unsigned int));
	if (num == 0 && t->pres == 0)
	{
		print_aux(t, ' ', t->width, 1);
		return (t);
	}
	length = get_tens(num);
	if (t->conver[0] == '-')
		flag = 1;
	if (t->conver[2] == '0' && t->pres == -1 && !t->conver[0])
		t->pres = t->width;
	logic_u(t, num, length, flag);
	return (t);
}

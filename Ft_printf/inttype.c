/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inttype.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:20:11 by adiaz-do          #+#    #+#             */
/*   Updated: 2020/11/19 20:20:12 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_tens(long int num)
{
	int		tens;

	if (num < 0)
		num *= -1;
	tens = 1;
	while ((num /= 10) > 0)
		tens++;
	return (tens);
}

static char		get_sign(t_t *t, int is_neg)
{
	char	*tmp;

	tmp = t->conver;
	if (is_neg)
		return ('-');
	if (tmp[1] == '+')
		return ('+');
	if (tmp[3] == ' ')
		return (' ');
	return ('\0');
}

static void		ft_putnbrintmax_fd(long int nb, int fd)
{
	long int	nbr;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = (long int)(nb * -1);
	}
	else
		nbr = (long int)nb;
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd((char)(nbr % 10 + 48), fd);
}

static t_t		*logic_d(t_t *t, long int num, int num_len, int align_left)
{
	int		not_blank;
	char	sign;
	int		is_negative;

	is_negative = (num < 0) ? 1 : 0;
	not_blank = num_len;
	num *= (is_negative) ? -1 : 1;
	sign = get_sign(t, is_negative);
	if (num_len <= t->pres && t->pres >= 0)
		not_blank = t->pres;
	if (sign)
		not_blank++;
	t->rv += (not_blank <= t->width) ? t->width : not_blank;
	if (!align_left && (t->conver[2] != '0' || t->pres >= 0))
		print_aux(t, ' ', t->width - not_blank, 0);
	if (sign)
		write(1, &sign, 1);
	if (t->conver[2] == '0' && t->pres < 0 && t->conver[0] != '-')
		print_aux(t, '0', t->width - not_blank, 0);
	print_aux(t, '0', t->pres - num_len, 0);
	ft_putnbrintmax_fd(num, 1);
	if (align_left)
		print_aux(t, ' ', t->width - not_blank, 0);
	return (t);
}

t_t				*inttype(t_t *t)
{
	int			num;
	long int	num_len;
	int			align_left;

	num = (long int)(va_arg(t->ap, int));
	if (num == 0 && t->pres == 0)
	{
		if (t->conver[1] == '+')
			write(1, "+", 1);
		if (t->conver[3] == ' ')
			write(1, " ", 1);
		print_aux(t, ' ', t->width, 1);
		return (t);
	}
	num_len = get_tens(num);
	(num > INT32_MAX) ? num_len++ : num_len;
	align_left = (t->conver[0] == '-') ? 1 : 0;
	logic_d(t, num, num_len, align_left);
	return (t);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hextype.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:20:00 by adiaz-do          #+#    #+#             */
/*   Updated: 2020/11/19 20:20:02 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		hashtag(int num, char hash, char x)
{
	if (num)
	{
		if (hash == '#' && x == 'x')
			write(1, "0x", 2);
		if (hash == '#' && x == 'X')
			write(1, "0X", 2);
	}
}

static int		aux(t_t *t, int num, char *str, int num_w)
{
	if ((num_w = ft_strlen(str)) && t->conver[4] == '#' && num &&
	t->conver[2] == '0' && t->width)
		num_w += 2;
	else if ((num_w = ft_strlen(str)) && t->conver[4] == '#' && num)
	{
		t->width -= 2;
		t->rv += 2;
	}
	return (num_w);
}

static t_t		*logic_x(t_t *t, unsigned int num, char *str, int align)
{
	int num_b;
	int num_w;

	num_w = 0;
	num_w = aux(t, num, str, num_w);
	num_b = (num_w <= t->pres && t->pres > 0)
	? t->pres : num_w;
	t->rv += (num_b <= t->width) ? t->width : num_b;
	if (!align && t->pres != -1)
		print_aux(t, ' ', t->width - num_b, 0);
	else if (t->conver[2] != '0' && !align)
		print_aux(t, ' ', t->width - num_b, 0);
	hashtag(num, t->conver[4], t->flag);
	if (t->conver[2] == '0' && t->pres < 0)
		print_aux(t, '0', t->width - num_b, 0);
	else
		print_aux(t, '0', t->pres - num_w, 0);
	ft_putstr_fd(str, 1);
	if (align)
		print_aux(t, ' ', t->width - num_b, 0);
	return (t);
}

t_t				*hextype(t_t *t)
{
	char			*str;
	char			c;
	unsigned int	num;
	int				align;

	align = 0;
	num = (unsigned int)(va_arg(t->ap, unsigned int));
	if (num == 0 && t->pres == 0)
	{
		print_aux(t, ' ', t->width, 1);
		return (t);
	}
	c = 'a';
	if (t->flag == 'X')
		c = 'A';
	if (!(str = ft_itoa_base(num, 16, c)))
		exit(-1);
	if (t->conver[0] == '-')
		align = 1;
	if (t->conver[2] == '0' && t->pres == -1 && !t->conver[0])
		t->pres = t->width;
	logic_x(t, num, str, align);
	free(str);
	return (t);
}

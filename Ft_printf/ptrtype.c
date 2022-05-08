/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptrtype.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:20:30 by adiaz-do          #+#    #+#             */
/*   Updated: 2020/11/19 20:30:01 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_t		*logic_p(t_t *t, char *str, int left)
{
	int		not_blank;
	int		length;

	length = ft_strlen(str) + 2;
	not_blank = length;
	t->rv += (not_blank <= t->width) ? t->width : not_blank;
	if (!left)
		print_aux(t, ' ', t->width - not_blank, 0);
	write(1, "0x", 2);
	print_aux(t, '0', (t->pres - length) + 2, 1);
	ft_putstr_fd(str, 1);
	if (left)
		print_aux(t, ' ', t->width - not_blank, 0);
	free(str);
	return (t);
}

t_t				*ptrtype(t_t *t)
{
	char		*str;
	long int	num;
	int			left;

	left = 0;
	num = (unsigned long int)(va_arg(t->ap, unsigned long int));
	if (!(str = ft_itoa_base(num, 16, 'a')))
		exit(-1);
	if (t->conver[0] == '-')
		left = 1;
	if (t->pres == 0 && num == 0)
		*str = '\0';
	if (t->conver[2] == '0' && t->pres == -1 && !t->conver[0])
	{
		t->pres = t->width - 2;
		t->width = 0;
	}
	logic_p(t, str, left);
	return (t);
}

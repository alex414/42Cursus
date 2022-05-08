/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:20:51 by adiaz-do          #+#    #+#             */
/*   Updated: 2020/11/19 20:20:52 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_t		*width(t_t *t)
{
	if (t->trat[t->i] == '*')
	{
		t->width = (int)(va_arg(t->ap, int));
		if (t->width <= 0)
		{
			t->width *= -1;
			t->conver[0] = '-';
			t->conver[2] = 'a';
		}
		t->i++;
	}
	while (t->trat[t->i] >= '0' && t->trat[t->i] <= '9')
	{
		t->width *= 10;
		t->width += (t->trat[t->i] - 48);
		t->i++;
	}
	return (t);
}

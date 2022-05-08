/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:19:48 by adiaz-do          #+#    #+#             */
/*   Updated: 2020/11/19 20:29:33 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printprintf(t_t *t)
{
	if (ft_strcmp(t->cpy, "%") == 0)
		return (0);
	while (t->cpy[t->i] != '\0')
	{
		if (t->cpy[t->i] == '%')
		{
			reinit(t);
			types(t);
			if (t->flag == 'q' && !va_arg(t->ap, int))
				return (0);
		}
		else
		{
			write(1, &t->cpy[t->i], 1);
			t->rv++;
		}
		t->i++;
	}
	return (t->rv);
}

int		ft_printf(const	char *fmt, ...)
{
	t_t *t;

	if (!(t = (t_t*)malloc(sizeof(t_t))))
		return (-1);
	t->str = fmt;
	init(t);
	if (fmt)
	{
		va_start(t->ap, fmt);
		t->rv = printprintf(t);
		va_end(t->ap);
	}
	free(t);
	return (t->rv);
}

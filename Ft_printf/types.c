/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:20:40 by adiaz-do          #+#    #+#             */
/*   Updated: 2020/11/19 20:30:07 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		types(t_t *t)
{
	t->i++;
	convertype(t);
	width(t);
	precision(t);
	flagtype(t);
	printtype(t);
	return (t->rv);
}

t_t		*printtype(t_t *t)
{
	char	ident;

	ident = t->flag;
	if (ident == 'd' || ident == 'i')
		inttype(t);
	else if (ident == 's')
		strtype(t);
	else if (ident == 'c')
		chartype(t);
	else if (ident == 'x' || ident == 'X')
		hextype(t);
	else if (ident == 'u')
		uninttype(t);
	else if (ident == 'p')
		ptrtype(t);
	else if (ident == '%')
	{
		t->flag = '%';
		chartype(t);
	}
	return (t);
}

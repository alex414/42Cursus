/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagtype.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:19:25 by adiaz-do          #+#    #+#             */
/*   Updated: 2020/11/19 20:19:27 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_t		*flagtype(t_t *t)
{
	size_t		j;

	j = 0;
	while (t->flagtype[j] != '\0')
	{
		if (t->flagtype[j] == t->trat[t->i])
			t->flag = t->flagtype[j];
		j++;
	}
	return (t);
}

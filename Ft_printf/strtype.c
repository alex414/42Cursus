/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtype.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:20:35 by adiaz-do          #+#    #+#             */
/*   Updated: 2020/11/19 20:20:36 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strndup(const char *s1, size_t n)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (!(s2 = ft_strnew(n)))
		return (NULL);
	while (s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

t_t			*strtype(t_t *t)
{
	char	*str;
	int		i;
	size_t	len;

	str = (char *)va_arg(t->ap, char *);
	i = 0;
	if (t->pres > -1 && str)
		str = ft_strndup(str, t->pres);
	else if (t->pres == -1 && str)
		str = ft_strdup(str);
	else if (t->pres > -1 && !str)
		str = ft_strndup("(null)", t->pres);
	else if (t->pres == -1 && !str)
		str = ft_strdup("(null)");
	len = ft_strlen(str);
	t->rv += len;
	if (t->conver[2] == '0' && t->conver[0] != '-')
		print_aux(t, '0', t->width - len, 1);
	else if (t->conver[0] != '-')
		print_aux(t, ' ', t->width - len, 1);
	ft_putstr_fd(str, 1);
	if (t->conver[0] == '-')
		print_aux(t, ' ', t->width - len, 1);
	free(str);
	return (t);
}

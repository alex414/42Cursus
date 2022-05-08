/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 10:45:12 by adiaz-do          #+#    #+#             */
/*   Updated: 2021/05/05 12:37:47 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ps1;
	const unsigned char	*ps2;

	if (n)
	{
		ps1 = s1;
		ps2 = s2;
		while (n-- > 0)
			if ((*(ps1++)) != (*(ps2++)))
				return ((int)((*(--ps1)) - (*(--ps2))));
	}
	return (0);
}

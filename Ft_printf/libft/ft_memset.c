/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:23:02 by adiaz-do          #+#    #+#             */
/*   Updated: 2020/11/19 20:23:03 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*newb;
	size_t			i;

	newb = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		newb[i] = (unsigned char)c;
		i++;
	}
	return (newb);
}

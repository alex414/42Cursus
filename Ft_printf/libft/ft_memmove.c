/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:22:52 by adiaz-do          #+#    #+#             */
/*   Updated: 2020/11/19 20:22:53 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = 0;
	if (dst != '\0' || src != '\0')
	{
		if (((unsigned char *)src) < ((unsigned char *)dst))
			while (len-- > 0)
				((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		else
			while (i < len)
			{
				((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
				i++;
			}
		return ((unsigned char *)dst);
	}
	return (NULL);
}

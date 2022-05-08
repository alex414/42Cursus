/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:24:42 by adiaz-do          #+#    #+#             */
/*   Updated: 2020/11/19 20:24:43 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t i;
	size_t j;

	i = 0;
	while (dest[i] != '\0' && i < destsize)
	{
		i++;
	}
	j = i;
	while (i + 1 < destsize && (src[i - j] != '\0'))
	{
		dest[i] = src[i - j];
		i++;
	}
	if (j < destsize)
		dest[i] = '\0';
	return (j + ft_strlen(src));
}

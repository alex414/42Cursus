/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:19:57 by adiaz-do          #+#    #+#             */
/*   Updated: 2020/01/16 11:47:48 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		target;
	int			i;

	target = ((char)c);
	i = ft_strlen(s);
	while (i > -1)
	{
		if (s[i] == target)
			return ((char *)s + i);
		i--;
	}
	return (0);
}

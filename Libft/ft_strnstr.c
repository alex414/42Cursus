/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:06:26 by adiaz-do          #+#    #+#             */
/*   Updated: 2020/01/13 13:36:59 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	needlen;

	if (!(*s2))
		return ((char *)s1);
	needlen = ft_strlen(s2);
	while (*s1 && (len-- >= needlen))
	{
		if ((*s1 == *s2) && (!ft_strncmp(s1, s2, needlen)))
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}

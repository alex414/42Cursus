/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:26:06 by adiaz-do          #+#    #+#             */
/*   Updated: 2020/11/19 20:26:08 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;

	if (!(s2 = (char *)malloc(sizeof(char) * len + 1)) || s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		*s2 = '\0';
		return (s2);
	}
	else
		ft_strlcpy(s2, s + start, len + 1);
	return (s2);
}

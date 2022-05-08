/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:25:54 by adiaz-do          #+#    #+#             */
/*   Updated: 2020/11/19 20:25:55 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_search(char c, const char *set)
{
	int k;
	int len_set;

	k = 0;
	len_set = ft_strlen(set);
	while (k < len_set)
	{
		if (c == set[k])
			return (1);
		k++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;
	size_t		len;
	char		*toreturn;

	i = 0;
	j = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	while (ft_search(s1[i], set))
		i++;
	while (len > 0 && ft_search(s1[len - 1], set))
		len--;
	if (len < i)
		len = i;
	toreturn = (char*)malloc(sizeof(char) * (len - i + 1));
	if (!toreturn)
		return (NULL);
	while (i < len)
		toreturn[j++] = (char)s1[i++];
	toreturn[j] = '\0';
	return (toreturn);
}

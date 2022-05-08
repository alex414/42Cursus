/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:23:35 by adiaz-do          #+#    #+#             */
/*   Updated: 2020/11/19 20:23:36 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			**ft_mallocsize(char const *s, char c)
{
	char	*aux;
	char	**aux2;
	int		fil;

	fil = 0;
	aux = (char*)s;
	while (*aux)
	{
		while (*aux == c)
			aux++;
		if (*aux != '\0')
			fil++;
		while (*aux != c && *aux)
			aux++;
	}
	aux2 = (char**)malloc((fil + 1) * sizeof(char*));
	if (aux2 == NULL)
		return (NULL);
	aux2[fil] = NULL;
	return (aux2);
}

static char			**ft_copy(const char *s, char c)
{
	size_t	len;
	char	**tab;
	int		i;

	i = 0;
	len = 0;
	tab = ft_mallocsize(s, c);
	if (tab == NULL)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			while (s[len] != c && s[len])
				len++;
			tab[i++] = ft_substr(s, 0, len);
			s += len;
		}
		len = 0;
	}
	tab[i] = NULL;
	return (tab);
}

char				**ft_split(char const *s, char c)
{
	char **tab;

	if (!s)
		return (NULL);
	tab = ft_copy(s, c);
	return (tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:15:08 by adiaz-do          #+#    #+#             */
/*   Updated: 2021/05/05 12:41:16 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	j;

	j = 0;
	while (s1[j] == s2[j] && s1[j] != '\0' && s2[j] != '\0')
		j++;
	return ((unsigned char)s1[j] - (unsigned char)(s2[j]));
}

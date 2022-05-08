/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_rep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:37:10 by adiaz-do          #+#    #+#             */
/*   Updated: 2022/05/08 13:47:04 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	no_rep(t_list *stk)
{
	int	*num;
	int	aux;
	int	i;
	int	j;

	num = (int *)malloc(ft_lstsize(stk) * sizeof(int));
	num_lst(stk, num);
	i = 0;
	while (i < ft_lstsize(stk))
	{
		aux = num[i];
		j = 0;
		while (j < ft_lstsize(stk))
		{
			if (j != i && aux == num[j])
				error();
			j++;
		}
		i++;
	}
	free(num);
}

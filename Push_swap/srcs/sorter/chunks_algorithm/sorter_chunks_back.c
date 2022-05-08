/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_chunks_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 22:20:03 by adiaz-do          #+#    #+#             */
/*   Updated: 2021/11/03 00:38:14 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_push_swap.h"

static int	biggest(int *num, int size)
{
	int	i;
	int	pos;
	int	big;

	i = 0;
	pos = 0;
	big = -2147483647;
	while (i < size)
	{
		if (num[i] > big)
		{
			big = num[i];
			pos = i;
		}
		i++;
	}
	if (pos > (size / 2))
		pos = (size - pos) * -1;
	return (pos);
}

void	chunks_back(t_list **stk_a, t_list **stk_b)
{
	int	*num;
	int	size;

	size = ft_lstsize(*stk_b);
	num = (int *)malloc(size * sizeof(int));
	while (size)
	{
		num_lst(*stk_b, num);
		moving_n_pushing_b(stk_b, biggest(num, size));
		operator_commands(stk_a, stk_b, "pa");
		size--;
	}
	free(num);
}

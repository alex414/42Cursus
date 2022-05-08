/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_chunks_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:37:58 by adiaz-do          #+#    #+#             */
/*   Updated: 2021/11/03 00:37:48 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_push_swap.h"

static int	small(int *num, int size)
{
	int	i;
	int	pos;
	int	small;

	i = 0;
	pos = 0;
	small = 2147483647;
	while (i < size)
	{
		if (num[i] < small)
		{
			small = num[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

static void	scanning_chunk(int stk_size, int chnum, int *chunk, int *num)
{
	int	j;
	int	i;

	j = 1;
	chunk[0] = num[small(num, stk_size)];
	while (j < chnum)
	{
		chunk[j] = 2147483647;
		i = 0;
		while (i < stk_size)
		{
			if ((num[i] < chunk[j]) && (num[i] > chunk[j - 1]))
				chunk[j] = num[i];
			i++;
		}
		j++;
	}
}

void	chunks_workout(t_list **stk_a, t_list **stk_b, int *num, int chnum)
{
	int	*chunk;
	int	stk_size;
	int	j;

	chunk = (int *)malloc(chnum * sizeof(int));
	if (!chunk)
		malloc_fail();
	stk_size = ft_lstsize(*stk_a);
	scanning_chunk(stk_size, chnum, chunk, num);
	j = chnum;
	while (j)
	{
		moving_n_pushing_a(stk_a, hold(chunk, num, stk_size, chnum));
		operator_commands(stk_a, stk_b, "pb");
		num_lst(*stk_a, num);
		j--;
		stk_size--;
	}
	free(chunk);
}

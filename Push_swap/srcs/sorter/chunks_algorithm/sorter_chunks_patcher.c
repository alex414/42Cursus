/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_chunks_patcher.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:37:47 by adiaz-do          #+#    #+#             */
/*   Updated: 2022/05/08 13:47:12 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	where_fail(int *num, int size, int *fail)
{
	int	i;
	int	pos;

	i = 0;
	while (i != (size - 1))
	{
		if (num[i] > num[i + 1])
		{
			*fail = num[i + 1];
			pos = i + 1;
		}
		i++;
	}
	if (pos > (size / 2))
		pos = (size - pos) * -1;
	return (pos);
}

static int	where_goes(int *num, int fail, int size)
{
	int	i;
	int	pos;

	i = 1;
	while (i != size)
	{
		if (num[i - 1] < fail && num[i] > fail)
			pos = i;
		i++;
	}
	if (pos > (size / 2))
		pos = (size - pos) * -1;
	return (pos);
}

void	patcher(t_list **stk_a, t_list **stk_b, int *num, int size)
{
	int	i;
	int	count;
	int	fail;

	i = where_fail(num, size, &fail);
	moving_n_pushing_a(stk_a, i);
	operator_commands(stk_a, stk_b, "pb");
	count = i;
	num_lst(*stk_a, num);
	i = where_goes(num, fail, size - 1);
	moving_n_pushing_a(stk_a, i);
	operator_commands(stk_a, stk_b, "pa");
	count += i;
	count = count * -1;
	moving_n_pushing_a(stk_a, count);
	num_lst(*stk_a, num);
	if (they_rigth(num, size))
		patcher(stk_a, stk_b, num, size);
}

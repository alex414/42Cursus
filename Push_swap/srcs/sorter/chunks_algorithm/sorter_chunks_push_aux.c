/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_chunks_push_aux.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:37:52 by adiaz-do          #+#    #+#             */
/*   Updated: 2022/05/08 13:47:15 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	up_function(int size, int chnum, int *num, int *chunk)
{
	int	up;
	int	i;

	i = 0;
	up = -1;
	while ((up <= (size / 2)) && i != -1)
	{
		i = 0;
		up++;
		while (i < chnum)
		{
			if (chunk[i] == num[up])
			{
				i = -1;
				break ;
			}
			i++;
		}
	}
	return (up);
}

static int	down_function(int size, int chnum, int *num, int *chunk)
{
	int	down;
	int	i;

	i = 0;
	down = size - 1;
	while ((down > (size / 2)) && i != -1)
	{
		down--;
		i = 0;
		while (i < chnum)
		{
			if (chunk[i] == num[down])
			{
				i = -1;
				break ;
			}
			i++;
		}
	}
	return (down);
}

int	hold(int *chunk, int *num, int stk_size, int chnum)
{
	int	up;
	int	down;

	up = up_function(stk_size, chnum, num, chunk);
	down = down_function(stk_size, chnum, num, chunk);
	if (up < (stk_size - down))
		return (up);
	else
		return (-(stk_size - down));
}

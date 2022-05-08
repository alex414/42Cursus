/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:38:06 by adiaz-do          #+#    #+#             */
/*   Updated: 2021/11/01 20:38:06 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moving_n_pushing_a(t_list **stk, int i)
{
	if (i > 0)
	{
		while (i)
		{
			operator_commands(stk, NULL, "ra");
			i--;
		}
	}
	else
	{
		while (i)
		{
			operator_commands(stk, NULL, "rra");
			i++;
		}
	}
}

void	moving_n_pushing_b(t_list **stk, int i)
{
	if (i > 0)
	{
		while (i)
		{
			operator_commands(NULL, stk, "rb");
			i--;
		}
	}
	else
	{
		while (i)
		{
			operator_commands(NULL, stk, "rrb");
			i++;
		}
	}
}

void	first_small(t_list **stk_b)
{
	int	*num;

	num = (int *)malloc(ft_lstsize(*stk_b) * sizeof(int));
	if (!num)
		malloc_fail();
	num_lst(*stk_b, num);
	moving_n_pushing_b(stk_b, search_small(num, ft_lstsize(*stk_b)));
	free(num);
}

void	chunks(t_list **stk_a, int *num)
{
	t_list	*stk_b;
	int		chnum;
	int		size;
	int		i;

	stk_b = NULL;
	size = ft_lstsize(*stk_a);
	i = ((float)(size) + 233.33333) / 66.66666;
	chnum = size / i;
	while (i)
	{
		chunks_workout(stk_a, &stk_b, num, chnum + 1);
		if (i == 2)
			chnum = ft_lstsize(*stk_a) - 4;
		i--;
	}
	num_lst(*stk_a, num);
	three_size(stk_a, num);
	chunks_back(stk_a, &stk_b);
	num_lst(*stk_a, num);
	if (they_rigth(num, size))
		patcher(stk_a, &stk_b, num, size);
}

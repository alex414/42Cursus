/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_shortmed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:38:18 by adiaz-do          #+#    #+#             */
/*   Updated: 2022/05/08 13:47:26 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_size(t_list *stk, int *num)
{
	if (num[0] > num[1])
	{
		swap(stk);
		write(1, "sa\n", 3);
	}
}

void	three_size(t_list **stk, int *num)
{
	if (num[0] < num[1] && num[1] > num[2] && num[0] < num[2])
	{
		operator_commands(stk, NULL, "rra");
		operator_commands(stk, NULL, "sa");
	}
	else if (num[0] < num[1] && num[1] > num[2] && num[0] > num[2])
	{
		operator_commands(stk, NULL, "rra");
	}
	else if (num[0] > num[1] && num[1] > num[2] && num[0] > num[2])
	{
		operator_commands(stk, NULL, "ra");
		operator_commands(stk, NULL, "sa");
	}
	else if (num[0] > num[1] && num[1] < num[2] && num[0] < num[2])
		operator_commands(stk, NULL, "sa");
	else if (num[0] > num[1] && num[1] < num[2] && num[0] > num[2])
		operator_commands(stk, NULL, "ra");
}

int	search_small(int *num, int size)
{
	int	i;
	int	pos;
	int	big;

	i = 0;
	pos = 0;
	big = 2147483647;
	while (i < size)
	{
		if (num[i] < big)
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

void	five_size(t_list **stk_a, int *num)
{
	t_list	*stk_b;
	int		j;

	j = 0;
	while (1)
	{
		moving_n_pushing_a(stk_a, search_small(num, ft_lstsize(*stk_a)));
		operator_commands(stk_a, &stk_b, "pb");
		j++;
		num_lst(*stk_a, num);
		if ((*stk_a)->next->next->next == NULL)
			break ;
	}
	three_size(stk_a, num);
	while (j)
	{
		operator_commands(stk_a, &stk_b, "pa");
		j--;
	}
}

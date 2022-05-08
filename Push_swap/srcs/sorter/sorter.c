/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:38:24 by adiaz-do          #+#    #+#             */
/*   Updated: 2021/11/02 21:49:40 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_push_swap.h"

void	operator_commands(t_list **stk_a, t_list **stk_b, char *command)
{
	if (!ft_strncmp(command, "pa", 2))
		push(stk_a, stk_b);
	else if (!ft_strncmp(command, "pb", 2))
		push(stk_b, stk_a);
	else if (!ft_strncmp(command, "sa", 2))
		swap(*stk_a);
	else if (!ft_strncmp(command, "sb", 2))
		swap(*stk_b);
	else if (!ft_strncmp(command, "ra", 2))
		rotate(stk_a);
	else if (!ft_strncmp(command, "rb", 2))
		rotate(stk_b);
	else if (!ft_strncmp(command, "rr", 3))
		rotate_rr(stk_a, stk_b);
	else if (!ft_strncmp(command, "rra", 3))
		reverse(stk_a);
	else if (!ft_strncmp(command, "rrb", 3))
		reverse(stk_b);
	else if (!ft_strncmp(command, "rrr", 3))
		reverse_rr(stk_a, stk_b);
	ft_putstr_fd(command, 1);
	write(1, "\n", 1);
}

int	they_rigth(int *num, int size)
{
	int	i;

	i = 0;
	while (i != (size - 1))
	{
		if (num[i] > num[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	sorter(t_list *stk)
{
	int	*num;
	int	stk_size;

	stk_size = ft_lstsize(stk);
	num = (int *)malloc(ft_lstsize(stk) * sizeof(int));
	num_lst(stk, num);
	no_rep(stk);
	if (they_rigth(num, stk_size))
	{
		if (stk_size == 2)
			two_size(stk, num);
		else if (stk_size == 3)
			three_size(&stk, num);
		else if (stk_size > 3 && stk_size < 31)
			five_size(&stk, num);
		else if (stk_size > 30)
			chunks(&stk, num);
	}
	free(num);
	ft_lstclear(&stk, clean_lst);
}

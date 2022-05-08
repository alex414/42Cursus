/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:37:06 by adiaz-do          #+#    #+#             */
/*   Updated: 2022/05/08 13:47:00 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	num_lst(t_list *stk, int *num)
{
	t_list	*aux;
	t_num	*number;
	int		i;

	aux = stk;
	i = 0;
	while (aux)
	{
		number = aux->content;
		num[i] = number->num;
		i++;
		aux = aux->next;
	}
	while (i != ft_lstsize(stk))
	{
		num[i] = 0;
		i++;
	}
}

static void	lst_take_num(char *arg, t_list **stk)
{
	t_num	*aux;

	aux = malloc(sizeof(t_num));
	if (!aux)
		error();
	ft_bzero(aux, sizeof(t_num));
	aux->num = ft_atoi_modified(arg);
	ft_lstadd_back(stk, ft_lstnew(aux));
}

static void	getting_that_arg(char *arg, t_list **stk)
{
	char	**ars;
	int		i;

	ars = ft_split(arg, ' ');
	i = 0;
	while (ars[i])
	{
		lst_take_num(ars[i], stk);
		i++;
	}
}

static void	putting_numrs(char *ars, t_list **stk)
{
	if (ft_strchr(ars, ' '))
		getting_that_arg(ars, stk);
	else
		lst_take_num(ars, stk);
}

t_list	*init_stk(int ar, char **ars)
{
	t_list	*stk;
	int		i;

	i = 1;
	stk = NULL;
	while (i != ar)
	{
		putting_numrs(ars[i], &stk);
		i++;
	}
	return (stk);
}

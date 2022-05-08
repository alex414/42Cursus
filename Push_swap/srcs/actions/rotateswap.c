/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotateswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 01:45:22 by adiaz-do          #+#    #+#             */
/*   Updated: 2021/11/03 05:40:56 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_push_swap.h"

void	rotate(t_list **stk)
{
	t_list	*first;
	t_list	*last;

	if (*stk == NULL || (*stk)->next == NULL)
		return ;
	first = *stk;
	last = *stk;
	while (last->next != NULL)
		last = last->next;
	*stk = (*stk)->next;
	first->next = NULL;
	last->next = first;
}

void	rotate_rr(t_list **stk_a, t_list **stk_b)
{
	rotate(stk_a);
	rotate(stk_b);
}

void	swap(t_list *stk)
{
	t_num	*tmp;

	if (!stk->next || stk == NULL)
		return ;
	tmp = stk->content;
	stk->content = stk->next->content;
	stk->next->content = tmp;
}

void	swap_ss(t_list *stk_a, t_list *stk_b)
{
	swap(stk_a);
	swap(stk_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushreverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 01:45:16 by adiaz-do          #+#    #+#             */
/*   Updated: 2021/11/03 05:40:43 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_push_swap.h"

void	reverse(t_list **stk)
{
	t_list	*first;
	t_list	*last;

	if (*stk == NULL || (*stk)->next == NULL)
		return ;
	first = *stk;
	last = *stk;
	while (last->next != NULL)
	{
		if (first->next->next != NULL)
			first = first->next;
		last = last->next;
	}
	last->next = *stk;
	first->next = NULL;
	*stk = last;
}

void	reverse_rr(t_list **stk_a, t_list **stk_b)
{
	reverse(stk_a);
	reverse(stk_b);
}

void	push(t_list **stk_dst, t_list **stk_src)
{
	t_list	*aux;

	if ((*stk_src) == NULL)
		return ;
	aux = *stk_src;
	*stk_src = (*stk_src)->next;
	if (!stk_dst)
		*stk_dst = ft_lstnew(aux->content);
	else
	{
		aux->next = *stk_dst;
		*stk_dst = aux;
	}
}

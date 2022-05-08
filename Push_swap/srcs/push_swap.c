/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:15:09 by adiaz-do          #+#    #+#             */
/*   Updated: 2022/05/08 13:47:34 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_lst(void *cont)
{
	t_num	*aux;

	aux = cont;
	free(aux);
}

void	malloc_fail(void)
{
	write(1, "Malloc :(\n", 20);
}

void	error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

int	main(int ar, char **ars)
{
	if (ar > 1)
		sorter(init_stk(ar, ars));
	return (0);
}

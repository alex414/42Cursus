/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 08:29:54 by adiaz-do          #+#    #+#             */
/*   Updated: 2021/05/04 08:29:55 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	swap(t_sprite *xp, t_sprite *yp)
{
	t_sprite	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void	sort_sprites(t_data *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->sprites_n - 1)
	{
		j = 0;
		while (j < vars->sprites_n - i - 1)
		{
			if (vars->sprites[j].distance <= vars->sprites[j + 1].distance)
				swap(&vars->sprites[j], &vars->sprites[j + 1]);
			j++;
		}
		i++;
	}
}

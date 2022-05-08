/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 08:29:26 by adiaz-do          #+#    #+#             */
/*   Updated: 2021/05/05 12:10:58 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_sprites_amount(t_data *data)
{
	int			i;
	int			j;
	int			k;
	t_sprite	sprite;

	i = 0;
	k = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
		{
			if (data->map.map[i][j] == '2')
			{
				sprite.map_x = i + 0.5;
				sprite.map_y = j + 0.5;
				data->sprites[k] = sprite;
				k++;
			}
			j++;
		}
		i++;
	}
	return (1);
}

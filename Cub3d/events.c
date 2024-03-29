/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 08:30:38 by adiaz-do          #+#    #+#             */
/*   Updated: 2021/05/05 11:25:05 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define W 13
#define A 0
#define S 1
#define D 2
#define ESC 53
#define SHIFT 257
#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124

int	ft_handle_key_press(int keycode, t_data *data)
{
	if (keycode == W)
		data->player.keys.w = 1;
	else if (keycode == A)
		data->player.keys.a = 1;
	else if (keycode == S)
		data->player.keys.s = 1;
	else if (keycode == D)
		data->player.keys.d = 1;
	else if (keycode == SHIFT)
		data->player.keys.shift = 1;
	else if (keycode == UP)
		data->player.keys.up = 1;
	else if (keycode == LEFT)
		data->player.keys.left = 1;
	else if (keycode == RIGHT)
		data->player.keys.right = 1;
	else if (keycode == DOWN)
		data->player.keys.down = 1;
	return (1);
}

int	ft_handle_key_release(int keycode, t_data *data)
{
	if (keycode == ESC)
		return (ft_close(data, 0));
	else if (keycode == W)
		data->player.keys.w = 0;
	else if (keycode == A)
		data->player.keys.a = 0;
	else if (keycode == S)
		data->player.keys.s = 0;
	else if (keycode == D)
		data->player.keys.d = 0;
	else if (keycode == SHIFT)
		data->player.keys.shift = 0;
	else if (keycode == UP)
		data->player.keys.up = 0;
	else if (keycode == LEFT)
		data->player.keys.left = 0;
	else if (keycode == RIGHT)
		data->player.keys.right = 0;
	else if (keycode == DOWN)
		data->player.keys.down = 0;
	return (1);
}

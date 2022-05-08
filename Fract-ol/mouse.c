/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:18:07 by adiaz-do          #+#    #+#             */
/*   Updated: 2021/06/21 21:07:47 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

static int	mouse_zoom_in(int x, int y, t_env *e)
{
	long double	zoom_factor;
	long double	move_x;
	long double	move_y;

	move_x = (long double)x * (long double)((e->max_x - e->min_x)
			/ (long double)WIDTH) + (long double)e->min_x;
	move_y = (long double)y * (long double)((e->max_y - e->min_y)
			/ (long double)HEIGHT) + (long double)e->min_y;
	zoom_factor = 0.9f;
	e->zoom *= zoom_factor;
	e->max_x = e->max_x * zoom_factor + move_x * (1 - zoom_factor);
	e->min_x = e->min_x * zoom_factor + move_x * (1 - zoom_factor);
	e->max_y = e->max_y * zoom_factor + move_y * (1 - zoom_factor);
	e->min_y = e->min_y * zoom_factor + move_y * (1 - zoom_factor);
	next_draw(e);
	return (0);
}

static int	mouse_zoom_out(int x, int y, t_env *e)
{
	long double	zoom_factor;
	long double	move_x;
	long double	move_y;

	if (e->zoom <= 2)
	{
		move_x = (long double)x * (long double)((e->max_x - e->min_x)
				/ (long double)WIDTH) + e->min_x;
		move_y = (long double)y * ((long double)(e->max_y - e->min_y)
				/ (long double)HEIGHT) + e->min_y;
		zoom_factor = 1.1f;
		e->zoom *= zoom_factor;
		e->max_x = e->max_x * zoom_factor + move_x * (1 - zoom_factor);
		e->min_x = e->min_x * zoom_factor + move_x * (1 - zoom_factor);
		e->max_y = e->max_y * zoom_factor + move_y * (1 - zoom_factor);
		e->min_y = e->min_y * zoom_factor + move_y * (1 - zoom_factor);
		next_draw(e);
	}
	return (0);
}

int	mouse_zoom(int keycode, int x, int y, t_env *e)
{
	if (keycode == 5 || keycode == 1)
		mouse_zoom_in(x, y, e);
	else if (keycode == 4 || keycode == 2)
		mouse_zoom_out(x, y, e);
	return (0);
}

int	mouse_for_julia(int x, int y, t_env *e)
{
	long double	x2;
	long double	y2;

	if (e->julia_mode_on == 1)
	{
		x2 = ft_map(x, add_params(0, WIDTH, -1, 1));
		y2 = ft_map(y, add_params(0, HEIGHT, -1, 1));
		e->c_re = x2;
		e->c_im = y2;
		next_draw(e);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:17:50 by adiaz-do          #+#    #+#             */
/*   Updated: 2021/06/21 21:08:19 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

static void	which_fractal(t_env *e)
{
	if (e->choose_fractal == 1)
	{
		e->function = mandelbrot_math;
	}
	else if (e->choose_fractal == 2)
	{
		e->function = julia_math;
		e->c_re = -0.70176f;
		e->c_im = -0.3842f;
	}
	else
		e->function = burning_ship_math;
}

void	init(t_env *e)
{
	e->function = mandelbrot_math;
	e->choose_color = 0;
	e->julia_mode_on = 0;
	e->min_x = -1.5f;
	e->max_x = 1.0f;
	e->min_y = -1.0f;
	e->max_y = 1.0f;
	e->move_x = 0.0f;
	e->move_y = 0.0f;
	e->zoom = 1.0f;
	e->infinity = 100;
	which_fractal(e);
}

void	foreach_pixel(t_env *e)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = e->function(e, x, y);
			choose_color(e, color);
			ft_drawing(e, x, y);
			x++;
		}
		y++;
	}
}

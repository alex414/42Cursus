/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:17:32 by adiaz-do          #+#    #+#             */
/*   Updated: 2021/06/21 21:10:27 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int	mandelbrot_math(t_env *e, int x, int y)
{
	long double	mx;
	long double	my;
	long double	c_im;
	long double	c_re;
	long double	x_temp;

	e->iteration = 0;
	mx = 0.0;
	my = 0.0;
	c_re = ft_map(x, add_params(0, WIDTH, e->min_x, e->max_x));
	c_im = ft_map(y, add_params(0, HEIGHT, e->min_y, e->max_y));
	while (e->iteration < e->infinity)
	{
		x_temp = (mx * mx - my * my) + c_re;
		my = 2.0f * mx * my + c_im;
		mx = x_temp;
		if ((mx * mx + my * my) > 4.0f)
			break ;
		e->iteration++;
	}
	return (e->iteration);
}

int	julia_math(t_env *e, int x, int y)
{
	long double	mx;
	long double	my;
	long double	x_temp;

	e->iteration = 0;
	mx = ft_map(x, add_params(0, WIDTH, e->min_x, e->max_x));
	my = ft_map(y, add_params(0, HEIGHT, e->min_y, e->max_y));
	while (e->iteration < e->infinity)
	{
		x_temp = (mx * mx - my * my) + e->c_re;
		my = 2.0f * mx * my + e->c_im;
		mx = x_temp;
		if ((mx * mx + my * my) > 4.0f)
			break ;
		e->iteration++;
	}
	return (e->iteration);
}

int	burning_ship_math(t_env *e, int x, int y)
{
	long double	mx;
	long double	my;
	long double	c_im;
	long double	c_re;
	long double	x_temp;

	e->iteration = 0;
	mx = 0.0;
	my = 0.0;
	c_re = ft_map(x, add_params(0, WIDTH, e->min_x, e->max_x));
	c_im = ft_map(y, add_params(0, HEIGHT, e->min_y, e->max_y));
	while (e->iteration < e->infinity)
	{
		x_temp = (mx * mx - my * my) + c_re;
		my = fabsl(2.0 * mx * my + c_im);
		mx = fabsl(x_temp);
		if ((mx * mx + my * my) > 4.0f)
			break ;
		e->iteration++;
	}
	return (e->iteration);
}

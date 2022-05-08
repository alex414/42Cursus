/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:17:44 by adiaz-do          #+#    #+#             */
/*   Updated: 2021/06/21 21:27:02 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

static void	more_colors(t_env *e, int depth)
{
	if (e->choose_color == 2)
	{
		e->red = ((depth * depth) * 30) % 255;
		e->blue = ((depth * depth) * 80) % 255;
		e->green = (depth * 40) % 255;
	}
	else if (e->choose_color == 3)
	{
		e->red = (depth * 5) % 255;
		e->blue = (depth * 5) % 255;
		e->green = (depth * 5) % 255;
	}
}

void	choose_color(t_env *e, int depth)
{
	if (e->choose_color == 0)
	{
		if (depth == e->infinity)
		{
			e->red = 0;
			e->blue = 0;
			e->green = 0;
		}
		else
		{
			e->red = (depth * 3) % 255;
			e->blue = (depth * 7) % 255;
			e->green = (depth * 4) % 255;
		}
	}
	else if (e->choose_color == 1)
	{
		e->red = (depth * 7) % 255;
		e->blue = (depth * 2) % 70;
		e->green = (depth * 3) % 4;
	}
	else
		more_colors(e, depth);
}

void	next_draw(t_env *e)
{
	mlx_clear_window(e->mlx_ptr, e->win_ptr);
	foreach_pixel(e);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->image_ptr, 0, 0);
}

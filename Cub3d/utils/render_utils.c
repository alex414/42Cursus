/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 08:30:24 by adiaz-do          #+#    #+#             */
/*   Updated: 2021/05/06 14:12:19 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_point	ft_create_point(float x, float y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

void	ft_draw_line(t_data *data, t_point start, t_point end,
	unsigned long color)
{
	float	x;
	float	y;
	int		i;
	t_line	line;

	line.dx = end.x - start.x;
	line.dy = end.y - start.y;
	if (abs(line.dx) > abs(line.dy))
		line.steps = abs(line.dx);
	else
		line.steps = abs(line.dy);
	line.x_inc = line.dx / (float)line.steps;
	line.y_inc = line.dy / (float)line.steps;
	x = start.x;
	y = start.y;
	i = 0;
	while (i <= line.steps)
	{
		ft_put_pixel(data, x, y, color);
		x += line.x_inc;
		y += line.y_inc;
		i++;
	}
}

void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	if (x < 0 || x >= data->width || y < 0 || y >= data->height)
		return ;
	data->img.addr[y * data->width + x] = color;
}

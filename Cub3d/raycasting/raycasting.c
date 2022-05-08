/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 08:29:45 by adiaz-do          #+#    #+#             */
/*   Updated: 2021/05/06 19:18:57 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_sides(t_data *data, t_ray *ray, t_wall *wall)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x
				 - data->player.x + (1 - ray->step_x) / 2) / ray->dir_x;
	else
		ray->perp_wall_dist = (ray->map_y
				 - data->player.y + (1 - ray->step_y) / 2) / ray->dir_y;
	if (ray->side == 0)
		if (ray->step_x == -1)
			wall->texture = data->textures.east;
	else
		wall->texture = data->textures.west;
	else if (ray->step_y == -1)
		wall->texture = data->textures.south;
	else
		wall->texture = data->textures.north;
	ray->line_height = (int)(data->height / ray->perp_wall_dist);
	wall->draw_start = -(ray->line_height) / 2 + data->height / 2;
	if (wall->draw_start < 0)
		wall->draw_start = 0;
	wall->draw_end = (ray->line_height) / 2 + data->height / 2;
	if (wall->draw_end >= data->height)
		wall->draw_end = data->height - 1;
}

void	ft_walls(t_data *data, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->map.map[ray->map_x][ray->map_y] == '1')
			ray->hit = 1;
	}
}

void	ft_steps(t_data *data, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->player.x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1 - data->player.x)
			* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->player.y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1 - data->player.y)
			* ray->delta_dist_y;
	}
}

void	ft_calculate_ray(t_data *data, t_ray *ray, t_wall *wall, int x)
{
	float	camera_x;

	camera_x = 2 * x / (float)data->width - 1;
	ray->hit = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->dir_x = data->player.dir_x + data->player.plane_x * camera_x;
	ray->dir_y = data->player.dir_y + data->player.plane_y * camera_x;
	ray->map_x = (int)data->player.x;
	ray->map_y = (int)data->player.y;
	if (ray->dir_y == 0)
		ray->delta_dist_x = 0;
	else if (ray->dir_x == 0)
		ray->delta_dist_x = 1;
	else
		ray->delta_dist_x = fabs(1 / ray->dir_x);
	if (ray->dir_x == 0)
		ray->delta_dist_y = 0;
	else if (ray->dir_y == 0)
		ray->delta_dist_y = 1;
	else
		ray->delta_dist_y = fabs(1 / ray->dir_y);
	ft_steps(data, ray), ft_walls(data, ray), ft_sides(data, ray, wall);
}

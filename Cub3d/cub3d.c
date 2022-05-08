/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 08:30:29 by adiaz-do          #+#    #+#             */
/*   Updated: 2021/05/10 19:34:53 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init(t_data *data)
{
	data->screenshot = 0;
	data->mlx_ptr = 0;
	data->mlx_win = 0;
	data->map.started = 0;
	data->map.empty_line = 0;
	data->player.keys.shift = 0;
	data->player.keys.w = 0;
	data->player.keys.a = 0;
	data->player.keys.s = 0;
	data->player.keys.d = 0;
	data->player.keys.left = 0;
	data->player.keys.right = 0;
	data->player.keys.up = 0;
	data->player.keys.down = 0;
	data->player.x = -1;
	data->player.y = -1;
	data->player.plane_x = 0;
	data->player.plane_y = 0.66;
	data->player.dir_x = -1;
	data->player.dir_y = 0;
	data->player.pitch = 0;
	data->key = 0;
}

int	render(t_data *data)
{
	t_ray		ray;
	t_wall		wall;
	int			x;

	x = 0;
	ft_movement(data);
	while (x < data->width)
	{
		ft_calculate_ray(data, &ray, &wall, x);
		ft_draw_line(data, ft_create_point(x, 0),
			ft_create_point(x, wall.draw_start),
			ft_t_rgb_to_hex(data->textures.ceiling));
		ft_draw_texture(data, wall, ray, x);
		ft_draw_line(data, ft_create_point(x, wall.draw_end),
			ft_create_point(x, data->height - 1),
			ft_t_rgb_to_hex(data->textures.floor));
		data->zbuffer[x] = ray.perp_wall_dist;
		x++;
	}
	calculate_sprite_distance(data);
	calculate_sprite_start(data);
	if (data->screenshot != 1)
		mlx_put_image_to_window(data->mlx_ptr,
			data->mlx_win, data->img.img, 0, 0);
	return (1);
}

int	main(int args_n, char **args)
{
	t_data	*dat;

	dat = malloc(sizeof(t_data));
	ft_init(dat);
	dat->mlx_ptr = mlx_init();
	if (!read_file(dat, args_n, args))
		return (ft_close(dat, 1));
	if (args[2] != NULL && ft_strncmp(args[2], "--save", 6) == 0)
		dat->screenshot = 1;
	if (dat->screenshot != 1)
		dat->mlx_win = mlx_new_window
			(dat->mlx_ptr, dat->width, dat->height, "cub3D");
	dat->img.img = mlx_new_image(dat->mlx_ptr, dat->width, dat->height);
	dat->img.addr = (unsigned int *)mlx_get_data_addr(dat->img.img,
			&dat->img.bits_per_pixel, &dat->img.line_length, &dat->img.endian);
	if (dat->screenshot != 1)
	{
		mlx_loop_hook(dat->mlx_ptr, render, dat);
		mlx_hook(dat->mlx_win, 02, 1L << 0, ft_handle_key_press, dat);
		mlx_hook(dat->mlx_win, 03, 1L << 1, ft_handle_key_release, dat);
		mlx_hook(dat->mlx_win, 17, 1L << 2, ft_close, dat);
		mlx_loop(dat->mlx_ptr);
	}
	ft_screenshot(dat), mlx_destroy_image(dat->mlx_ptr, dat->img.img);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 08:29:29 by adiaz-do          #+#    #+#             */
/*   Updated: 2021/05/10 18:50:48 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_null_texture(t_data *vars, int type)
{
	if (type == 1)
		if (vars->textures.north.height != -1 )
			return (0);
	else
		return (1);
	else if (type == 2)
		if (vars->textures.south.height != -1 )
			return (0);
	else
		return (1);
	else if (type == 3)
		if (vars->textures.east.height != -1)
			return (0);
	else
		 	return (1);
	else if (type == 4)
		if (vars->textures.west.height != -1)
			return (0);
	else
		return (1);
	else
		if (vars->textures.sprite.height != -1)
			return (0);
	else
		return (1);
}

int	save_texture_dir(t_data *vars, int type, char *str)
{
	if (type == 1)
		(vars->textures.north.path = ft_strtrim(str, " ")) && vars->key++;
	else if (type == 2)
		(vars->textures.south.path = ft_strtrim(str, " ")) && vars->key++;
	else if (type == 3)
		(vars->textures.east.path = ft_strtrim(str, " ")) && vars->key++;
	else if (type == 4)
		(vars->textures.west.path = ft_strtrim(str, " ")) && vars->key++;
	else
		vars->textures.sprite.path = ft_strtrim(str, " ");
	return (1);
}

int	ft_init_texture(t_data *data, t_texture *texture, char *path)
{
	int	fd;

	if (check_extension(path, ".xpm") == 0)
		return (0);
	fd = open(path, O_RDONLY);
	if (texture->img.addr)
		return (0);
	if ((fd) == -1)
	{
		close(fd);
		return (0);
	}
	texture->img.img = mlx_xpm_file_to_image(data->mlx_ptr, texture->path,
			&texture->width, &texture->height);
	if (!texture->img.img)
		return (0);
	texture->img.addr = (unsigned int *)mlx_get_data_addr(texture->img.img,
			&texture->img.bits_per_pixel, &texture->img.line_length,
			&texture->img.endian);
	return (1);
}

int	ft_init_textures_type(t_data *data, int type)
{
	if (type == 1)
		return (ft_init_texture(data, &data->textures.north,
				data->textures.north.path));
	else if (type == 2)
		return (ft_init_texture(data, &data->textures.south,
				data->textures.south.path));
	else if (type == 3)
		return (ft_init_texture(data, &data->textures.east,
				data->textures.east.path));
	else if (type == 4)
		return (ft_init_texture(data, &data->textures.west,
				data->textures.west.path));
	else if (type == 5)
		return (ft_init_texture(data, &data->textures.sprite,
				data->textures.sprite.path));
	return (1);
}

int	parse_texture_line(t_data *vars, int type, char *str)
{
	int	i;

	if (type == 5)
		i = 1;
	else
		i = 2;
	if (!ft_isspace(str[i]))
		return (0);
	while (ft_isspace(str[i]))
		i++;
	if (!ft_isascii(str[i]))
		return (0);
	if (!save_texture_dir(vars, type, &str[i]))
		return (0);
	if (!ft_init_textures_type(vars, type))
		return (0);
	return (1);
}

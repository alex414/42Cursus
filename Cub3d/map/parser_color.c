/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 08:29:07 by adiaz-do          #+#    #+#             */
/*   Updated: 2021/05/10 19:01:28 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	valid_colors(t_data *vars, int type)
{
	if (type == 1 && vars->textures.ceiling[0] >= 0
		&& vars->textures.ceiling[0] <= 255
		&& vars->textures.ceiling[1] >= 0 && vars->textures.ceiling[1] <= 255
		&& vars->textures.ceiling[2] >= 0 && vars->textures.ceiling[2] <= 255)
		return (1);
	if (type == 2 && vars->textures.floor[0] >= 0 && vars->textures.floor[0]
		<= 255
		&& vars->textures.floor[1] >= 0 && vars->textures.floor[1] <= 255
		&& vars->textures.floor[2] >= 0 && vars->textures.floor[2] <= 255)
		return (1);
	return (0);
}

int	valid_color(t_data *vars, int type)
{
	if (type == 1)
	{
		return (vars->textures.ceiling[0] != -1 && vars->textures.ceiling[1]
			!= -1 && vars->textures.ceiling[2] != -1);
	}
	else if (type == 2)
	{
		return (vars->textures.floor
			[0] != -1 && vars->textures.floor[1]
			!= -1 && vars->textures.floor[2] != -1);
	}
	return (1);
}

int	save_color(t_data *vars, int type, int color, char *str)
{
	if (!ft_isdigit(str[0]))
		return (0);
	if (type == 1)
	{
		if (valid_color(vars, 1) == 1)
			return (0);
		if (color == 0)
			vars->textures.ceiling[0] = ft_atoi(str);
		else if (color == 1)
			vars->textures.ceiling[1] = ft_atoi(str);
		else
			vars->textures.ceiling[2] = ft_atoi(str);
	}
	else
	{
		if (valid_color(vars, 2) == 1)
			return (0);
		if (color == 0)
			vars->textures.floor[0] = ft_atoi(str);
		else if (color == 1)
			vars->textures.floor[1] = ft_atoi(str);
		else
			vars->textures.floor[2] = ft_atoi(str);
	}
	return (1);
}

int	parse_color_line(t_data *vars, int type, char *str)
{
	int	i;
	int	j;

	i = 1;
	while (ft_isspace(str[i]))
		i++;
	j = -1;
	while (++j < 3)
	{
		while (ft_isspace(str[i]))
			i++;
		if (!save_color(vars, type, j, &str[i]))
			return (0);
		while (ft_isdigit(str[i]))
			i++;
		if (j != 2 && str[i] != ',')
			return (0);
		if (str[i] == ',')
			i++;
	}
	if (!empty_end_of_line(&str[i]) || (valid_colors(vars, type) == 0))
		return (0);
	else
		return (1);
}

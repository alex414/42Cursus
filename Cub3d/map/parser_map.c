/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 08:29:18 by adiaz-do          #+#    #+#             */
/*   Updated: 2021/05/10 20:40:43 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	count_map_size(t_data *vars, char *str)
{
	int	line_size;

	if (!check_variables(vars))
		return (0);
	line_size = ft_strlen(str);
	if (vars->map.width < line_size)
		vars->map.width = line_size;
	vars->map.height++;
	return (1);
}

int	fill_map(t_data *vars, char *line, int i)
{
	int	j;

	j = 0;
	while (line[j] != '\0')
	{
		if (!ft_strchr(" 012NESW", line[j]))
			return (0);
		if (line[j] == '2')
			vars->sprites_n += 1;
		if (line[j] == ' ')
			vars->map.map[i][j] = '0';
		else
			vars->map.map[i][j] = line[j];
		j++;
	}
	if (!check_player_pos(vars, i, line))
	{
		free(line);
		return (0);
	}
	return (1);
}

int	alloc_map(t_data *vars)
{
	int	i;
	int	j;

	vars->map.map = malloc(vars->map.height * sizeof(char *));
	i = 0;
	while (i < vars->map.height)
	{
		j = 0;
		vars->map.map[i] = malloc(vars->map.width * sizeof(char));
		while (j < vars->map.width)
		{
			vars->map.map[i][j] = '0';
			j++;
		}
		i++;
	}
	return (1);
}

int	nisu(t_data *vars, char *line, int *i)
{
	int	j;

	j = 0;
	while (ft_isspace(line[j]))
		j++;
	if (ft_isdigit(line[j]))
	{
		if (vars->map.started && vars->map.empty_line)
			return (0);
		vars->map.started = 1;
		if (!(fill_map(vars, line, *i)))
			return (0);
		*i += 1;
	}
	else
	{
		if (vars->map.started)
			vars->map.empty_line = 1;
	}
	return (1);
}

int	parse_map(t_data *vars, int fd)
{
	char	*line;
	int		i;

	if (!alloc_map(vars))
		return (0);
	i = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		if (!nisu(vars, line, &i))
			return (0);
		free(line);
	}
	if (!nisu(vars, line, &i))
		return (0);
	free(line);
	if (vars->player.x == -1 || vars->player.y == -1)
		return (0);
	return (1);
}

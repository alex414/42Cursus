/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 08:29:22 by adiaz-do          #+#    #+#             */
/*   Updated: 2021/05/10 18:18:00 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	is_max_resolution(t_data *vars)
{
	if (vars->width > 2560)
		vars->width = 2560;
	if (vars->height > 1440)
		vars->height = 1440;
}

int	parse_resolution_line(t_data *vars, char *str)
{
	int	i;

	i = 1;
	if (vars->width != -1 || vars->height != -1 || !ft_isspace(str[i]))
		return (0);
	while (ft_isspace(str[i]))
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	vars->width = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	while (ft_isspace(str[i]))
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	vars->height = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	if (!empty_end_of_line(&str[i]))
		return (0);
	is_max_resolution(vars);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:17:39 by adiaz-do          #+#    #+#             */
/*   Updated: 2021/06/21 21:08:42 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

static int	exit_x(void)
{
	exit(1);
	return (0);
}

static int	arguments_handler(char *str)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
		return (1);
	else if (ft_strcmp(str, "julia") == 0)
		return (2);
	else if (ft_strcmp(str, "burningship") == 0)
		return (3);
	else
		return (0);
}

static void	param_list(void)
{
	ft_putstr("List of available parameters:\n");
	ft_putstr("1: mandelbrot\n");
	ft_putstr("2: julia\n");
	ft_putstr("3: burningsship\n");
}

int	main(int argc, char *argv[])
{
	t_env	*e;

	if (argc == 2 && (arguments_handler(argv[1]) != 0))
	{
		e = malloc(sizeof(t_env));
		if (!(e))
			return (0);
		if (init_mlx(e) == 0)
			return (0);
		e->choose_fractal = arguments_handler(argv[1]);
		init(e);
		foreach_pixel(e);
		next_draw(e);
		mlx_hook(e->win_ptr, 2, 5, key_draw, e);
		mlx_hook(e->win_ptr, 17, 1L << 17, exit_x, NULL);
		mlx_mouse_hook(e->win_ptr, mouse_zoom, e);
		mlx_hook(e->win_ptr, MOTION_NOTIFY, 1L << 6, mouse_for_julia, e);
		mlx_loop(e->mlx_ptr);
	}
	else
		param_list();
	return (0);
}

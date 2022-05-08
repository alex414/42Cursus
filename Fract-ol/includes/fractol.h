/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:51:41 by adiaz-do          #+#    #+#             */
/*   Updated: 2021/06/21 21:26:46 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"
# define WIDTH 		800
# define HEIGHT		600
# define MOTION_NOTIFY	6

typedef struct s_map
{
	long double			min_in;
	long double			max_in;
	long double			min_out;
	long double			max_out;

}						t_map;

typedef struct s_env
{
	int					(*function)(struct s_env *e, int x, int y);
	void				*mlx_ptr;
	void				*win_ptr;
	void				*image_ptr;
	char				*image;
	int					bpp;
	int					en;
	int					ln;
	float				infinity;
	long double			c_re;
	long double			c_im;
	long double			min_x;
	long double			max_x;
	long double			min_y;
	long double			max_y;
	int					iteration;
	int					red;
	int					green;
	int					blue;
	int					choose_color;
	int					choose_fractal;
	int					julia_mode_on;
	long double			center_x;
	long double			center_y;
	long double			zoom;
	long double			move_x;
	long double			move_y;
	long double			start_y;
	long double			end_y;
}						t_env;

void					init(t_env *e);
long double				ft_map(long double x, t_map p);
int						mandelbrot_math(t_env *e, int x, int y);
int						julia_math(t_env *e, int x, int y);
int						burning_ship_math(t_env *e, int x, int y);
int						key_draw(int keycode, t_env *e);
void					foreach_pixel(t_env *e);
void					ft_drawing(t_env *e, int x, int y);
int						init_mlx(t_env *e);
void					next_draw(t_env *e);
void					choose_color(t_env *e, int color);
int						mouse_zoom(int keycode, int x, int y, t_env *e);
int						mouse_for_julia(int x, int y, t_env *e);
t_map					add_params(long double a, long double b,
							long double c, long double d);

#endif

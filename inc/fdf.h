/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 15:08:20 by gsaynac           #+#    #+#             */
/*   Updated: 2015/09/14 11:03:40 by gsaynac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define W					1920
# define H					1080

# define KEY_ESCAPE				53
# define KEY_MOVE_UP			126
# define KEY_MOVE_DOWN			125
# define KEY_MOVE_RIGHT			124
# define KEY_MOVE_LEFT			123
# define KEY_ZOOM_IN			69
# define KEY_ZOOM_OUT			78
# define MOUSE_ZOOM_IN			4
# define MOUSE_ZOOM_OUT			5
# define KEY_SCALE_X_UP			89
# define KEY_SCALE_X_DOWN		86
# define KEY_SCALE_Y_UP			91
# define KEY_SCALE_Y_DOWN		87
# define KEY_DEPTH_UP			92
# define KEY_DEPTH_DOWN			88
# define KEY_RESET				82
# define KEY_CENTER				65
# define KEY_COLOR_1			83
# define KEY_COLOR_2			84
# define KEY_COLOR_3			85

# include <libft.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>

typedef struct		s_xyz
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				z1;
	int				z2;
}					t_xyz;

typedef	struct		s_img
{
	void			*img;
	void			*data;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_img			img;
}					t_mlx;

typedef struct		s_map
{
	int				nb_line;
	int				nb_column;
	int				z_max;
	int				**matrix;
}					t_map;

typedef struct		s_set
{
	int				y_scale;
	int				x_scale;
	int				depth;
	int				margin_left;
	int				margin_top;
	int				main_color;
}					t_set;

typedef struct		s_fdf
{
	t_mlx			mlx;
	t_map			map;
	t_set			settings;
}					t_fdf;

void				ft_mlx_init(t_fdf *fdf);
void				ft_clear_image(t_fdf *fdf);
void				ft_error(char *error);
void				ft_parse(char *filename, t_fdf *fdf);
void				ft_set_settings(t_fdf *fdf);
void				ft_center(t_fdf *fdf);
void				ft_process(t_fdf *fdf);
void				ft_draw(int x, int y, t_fdf *fdf);
int					ft_mouse_hook(int keycode, int x, int y, t_fdf *fdf);
int					ft_key_hook(int keycode, t_fdf *fdf);
int					ft_expose_hook(t_fdf *f);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/14 10:36:22 by gsaynac           #+#    #+#             */
/*   Updated: 2015/09/14 11:45:03 by gsaynac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void		ft_zoom(int in, t_fdf *fdf)
{
	if (in)
	{
		fdf->settings.y_scale *= 2;
		fdf->settings.x_scale *= 2;
	}
	else if (fdf->settings.y_scale / 2 >= 1 && fdf->settings.x_scale / 2 >= 1)
	{
		fdf->settings.y_scale /= 2;
		fdf->settings.x_scale /= 2;
	}
}

int				ft_mouse_hook(int keycode, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (keycode == MOUSE_ZOOM_IN)
		ft_zoom(1, fdf);
	else if (keycode == MOUSE_ZOOM_OUT)
		ft_zoom(0, fdf);
	ft_clear_image(fdf);
	ft_process(fdf);
	return (0);
}

int				ft_expose_hook(t_fdf *f)
{
	mlx_put_image_to_window(f->mlx.mlx, f->mlx.win, f->mlx.img.img, 0, 0);
	return (0);
}

static void		ft_key_hook_2(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_SCALE_X_UP)
		fdf->settings.x_scale++;
	else if (keycode == KEY_SCALE_X_DOWN)
		fdf->settings.x_scale += fdf->settings.x_scale > 1 ? -1 : 0;
	else if (keycode == KEY_SCALE_Y_UP)
		fdf->settings.y_scale++;
	else if (keycode == KEY_SCALE_Y_DOWN)
		fdf->settings.y_scale += fdf->settings.y_scale > 1 ? -1 : 0;
	else if (keycode == KEY_CENTER)
		ft_center(fdf);
	else if (keycode == KEY_RESET)
		ft_set_settings(fdf);
	else if (keycode == KEY_COLOR_1)
		fdf->settings.main_color = 0;
	else if (keycode == KEY_COLOR_2)
		fdf->settings.main_color = 1;
	else if (keycode == KEY_COLOR_3)
		fdf->settings.main_color = 2;
}

int				ft_key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESCAPE)
		exit(0);
	else if (keycode == KEY_ZOOM_IN)
		ft_zoom(1, fdf);
	else if (keycode == KEY_ZOOM_OUT)
		ft_zoom(0, fdf);
	else if (keycode == KEY_MOVE_UP)
		fdf->settings.margin_top += 10;
	else if (keycode == KEY_MOVE_DOWN)
		fdf->settings.margin_top -= 10;
	else if (keycode == KEY_MOVE_LEFT)
		fdf->settings.margin_left += 10;
	else if (keycode == KEY_MOVE_RIGHT)
		fdf->settings.margin_left -= 10;
	else if (keycode == KEY_DEPTH_UP)
		fdf->settings.depth += fdf->settings.depth == -1 ? 2 : 1;
	else if (keycode == KEY_DEPTH_DOWN)
		fdf->settings.depth -= fdf->settings.depth == 1 ? 2 : 1;
	else
		ft_key_hook_2(keycode, fdf);
	ft_clear_image(fdf);
	ft_process(fdf);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 15:52:38 by gsaynac           #+#    #+#             */
/*   Updated: 2015/08/26 18:01:18 by gsaynac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void		ft_clear_image(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	while (i < H)
	{
		j = 0;
		while (j < W)
		{
			*((int*)(fdf->mlx.img.data + i * fdf->mlx.img.size_line + j * (fdf->mlx.img.bpp / 8))) = 0x000000;
			j++;
		}
		i++;
	}
}

static void		ft_zoom(int in, t_fdf *fdf)
{
	if (in)
	{
		fdf->settings.y_scale *= 2;
		fdf->settings.x_scale *= 2;
	}
	else if (fdf->settings.y_scale / 2 > 1 && fdf->settings.x_scale / 2 > 1)
	{
		fdf->settings.y_scale /= 2;
		fdf->settings.x_scale /= 2;
	}
}

static int		ft_mouse_hook(int keycode, int x, int y, t_fdf *fdf)
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

static int		ft_key_hook(int keycode, t_fdf *fdf)
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
	else if (keycode == KEY_SCALE_X_UP)
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
	ft_clear_image(fdf);
	ft_process(fdf);
	return (0);
}

static int		ft_hook_expose(t_fdf *fdf)
{
	mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->mlx.img.img, 0, 0);
	return (0);
}

void			ft_mlx_init(t_fdf *fdf)
{
	if (!(fdf->mlx.mlx = mlx_init()))
		ft_error("failed to init mlx");
	if (!(fdf->mlx.win = mlx_new_window(fdf->mlx.mlx, W, H, "fdf")))
		ft_error("failed to create new window");
	if (!(fdf->mlx.img.img = mlx_new_image(fdf->mlx.mlx, W, H)))
		ft_error("failed to create new image");
	if (!(fdf->mlx.img.data = mlx_get_data_addr(fdf->mlx.img.img, &fdf->mlx.img.bpp, &fdf->mlx.img.size_line, &fdf->mlx.img.endian)))
		ft_error("failed to get image datas");
	mlx_key_hook(fdf->mlx.win, ft_key_hook, fdf);
	mlx_mouse_hook(fdf->mlx.win, ft_mouse_hook, fdf);
	mlx_do_key_autorepeatoff(fdf->mlx.mlx);
	mlx_expose_hook(fdf->mlx.win, ft_hook_expose, fdf);
}

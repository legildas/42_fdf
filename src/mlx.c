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

static int		hook_key(int keycode, t_fdf *fdf)
{
	(void)fdf;
	if (keycode == KEY_ESCAPE)
		exit(0);
	return (0);
}

static int		hook_expose(t_fdf *fdf)
{
	(void)fdf;
	return (0);
}

void			ft_mlx_init(t_fdf *fdf)
{
	if (!(fdf->mlx.mlx = mlx_init()))
		ft_error("failed to init mlx");
	if (!(fdf->mlx.win = mlx_new_window(fdf->mlx.mlx, W, H, "fdf")))
		ft_error("failed to create new window");
	mlx_key_hook(fdf->mlx.win, hook_key, fdf);
	mlx_expose_hook(fdf->mlx.win, hook_expose, fdf);
	mlx_loop(fdf->mlx.mlx);
}

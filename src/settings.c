/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 00:59:26 by gsaynac           #+#    #+#             */
/*   Updated: 2015/09/08 00:59:28 by gsaynac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		ft_center(t_fdf *fdf)
{
	int		y[2];
	int		x[2];
	int 	height;
	int		width;

	y[0] = fdf->map.nb_line * fdf->settings.y_scale * -1;
	y[1] = fdf->map.nb_column * fdf->settings.y_scale;
	x[0] = 0;
	x[1] = (fdf->map.nb_column + fdf->map.nb_line - 2) * fdf->settings.x_scale;
	height = y[1] - y[0];
	width = x[1] - x[0];
	fdf->settings.margin_left = (W / 2) - (width / 2);
	fdf->settings.margin_top = (H / 2) - (height / 2) + y[1];
}

void			ft_set_settings(t_fdf *fdf)
{
	fdf->settings.y_scale = H / fdf->map.nb_line / 4;
	fdf->settings.x_scale = W / fdf->map.nb_column / 2;
	fdf->settings.depth = 2;
	fdf->settings.main_color = 0;
	ft_center(fdf);
}

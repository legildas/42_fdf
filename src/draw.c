/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 14:50:18 by gsaynac           #+#    #+#             */
/*   Updated: 2015/09/06 14:50:20 by gsaynac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void		ft_draw_line_1(t_xyz xyz, t_fdf fdf)
{
	int		x;
	int		y;
	int		color;
	int		to_add;
	float	slope;

	x = xyz.x1;
	y = xyz.y1;
	slope = 0.0;
	color = 0xffffff;//1*256*256 - (1 + (xyz.z1 <= xyz.z2 ? xyz.z1: xyz.z2));
	while (x < xyz.x2)
	{
		*((int*)(fdf.mlx.img.data + (y + fdf.settings.margin_top) * fdf.mlx.img.size_line + (x + fdf.settings.margin_left) * (fdf.mlx.img.bpp / 8))) = color;
		slope += (float)(xyz.y2 - y) / (float)(xyz.x2 - x);
		to_add = ft_floor(slope);
		slope -= ft_floor(slope);
		x += 1;
		y += to_add;
	}
}

static void		ft_draw_line_2(t_xyz xyz, t_fdf fdf)
{
	int		x;
	int		y;
	int		to_add;
	float	slope;
	int		color;

	x = xyz.x1;
	y = xyz.y1;
	slope = 0.0;
	color = 0xffffff;//1*256*256 - (1 + (xyz.z1 <= xyz.z2 ? xyz.z1: xyz.z2));
	while (y < xyz.y2)
	{
		*((int*)(fdf.mlx.img.data + (y + fdf.settings.margin_top) * fdf.mlx.img.size_line + (x + fdf.settings.margin_left) * (fdf.mlx.img.bpp / 8))) = color;
		slope += (float)(xyz.x2 - x) / (float)(xyz.y2 - y);
		to_add = ft_floor(slope);
		slope -= ft_floor(slope);
		y += 1;
		x += to_add;
	}
}

void			ft_draw(int x, int y, t_fdf *fdf)
{
	t_xyz	xyz;

	xyz.x1 = (x + y) * fdf->settings.x_scale;
	xyz.x2 = (x + y + 1) * fdf->settings.x_scale;

	xyz.z1 = fdf->map.matrix[y][x] * fdf->settings.depth;
	xyz.z2 = fdf->map.matrix[y][x + 1] * fdf->settings.depth;

	xyz.y1 = y * fdf->settings.y_scale - xyz.z1;
	xyz.y2 = y * fdf->settings.y_scale - xyz.z2;

	ft_draw_line_1(xyz, *fdf);
	ft_draw_line_2(xyz, *fdf);

	xyz.z2 = fdf->map.matrix[y + 1][x] * fdf->settings.depth;

	xyz.y2 = (y + 1) * fdf->settings.y_scale - xyz.z2;;

	ft_draw_line_1(xyz, *fdf);
	ft_draw_line_2(xyz, *fdf);
}

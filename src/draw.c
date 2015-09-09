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

static void		ft_draw_pixel(int x, int y, int color, t_fdf fdf)
{
	x += fdf.settings.margin_left;
	y += fdf.settings.margin_top;
	if (x > 0 && x < W && y > 0 && y < H)
		*((int*)(fdf.mlx.img.data + y * fdf.mlx.img.size_line + x * (fdf.mlx.img.bpp / 8))) = color;
}

static void		ft_draw_line(t_xyz xyz, t_fdf fdf)
{
	int	x;
	int	color;

	x = xyz.x1;
	color = 0xffffff;
	while (x++ < xyz.x2)
		ft_draw_pixel(x, xyz.y1 + ((xyz.y2 - xyz.y1) * (x - xyz.x1)) / (xyz.x2 - xyz.x1), color, fdf);
	while (x-- > xyz.x2)
		ft_draw_pixel(x, xyz.y1 + ((xyz.y2 - xyz.y1) * (x - xyz.x1)) / (xyz.x2 - xyz.x1), color, fdf);
}

static void		ft_draw_line_2(t_xyz xyz, t_fdf fdf)
{
	int	y;
	int	color;

	y = xyz.y1;
	color = 0xffffff;
	while (y++ < xyz.y2)
		ft_draw_pixel(xyz.x1 + ((xyz.x2 - xyz.x1) * (y - xyz.y1)) / (xyz.y2 - xyz.y1), y, color, fdf);
	while (y-- > xyz.y2)
		ft_draw_pixel(xyz.x1 + ((xyz.x2 - xyz.x1) * (y - xyz.y1)) / (xyz.y2 - xyz.y1), y, color, fdf);
}

void			ft_draw(int x, int y, t_fdf *fdf)
{
	t_xyz	xyz;

	xyz.x1 = (x + y) * fdf->settings.x_scale;
	xyz.x2 = (x + y + 1) * fdf->settings.x_scale;
	xyz.z1 = fdf->map.matrix[y][x] * fdf->settings.depth;
	xyz.y1 = (y - x) * fdf->settings.y_scale - xyz.z1;
	if (x + 1 < fdf->map.nb_column)
	{
		xyz.z2 = fdf->map.matrix[y][x + 1] * fdf->settings.depth;
		xyz.y2 = (y - x - 1) * fdf->settings.y_scale - xyz.z2;
		if (ft_fabs(xyz.x2 - xyz.x1) > ft_fabs(xyz.y2 - xyz.y1))
			ft_draw_line(xyz, *fdf);
		else
			ft_draw_line_2(xyz, *fdf);
	}
	if (y + 1 < fdf->map.nb_line)
	{
		xyz.z2 = fdf->map.matrix[y + 1][x] * fdf->settings.depth;
		xyz.y2 = (y - x + 1) * fdf->settings.y_scale - xyz.z2;;
		if (ft_fabs(xyz.x2 - xyz.x1) > ft_fabs(xyz.y2 - xyz.y1))
			ft_draw_line(xyz, *fdf);
		else
			ft_draw_line_2(xyz, *fdf);
	}
}

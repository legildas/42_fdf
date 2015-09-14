/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 14:50:18 by gsaynac           #+#    #+#             */
/*   Updated: 2015/09/14 12:51:40 by gsaynac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int		ft_get_color(int z1, int z2, t_fdf *fdf)
{
	int		rgb[3];
	int		z;

	rgb[0] = 150;
	rgb[1] = 150;
	rgb[2] = 150;
	if (z1 == z2)
		z = ft_fabs(z1);
	else
		z = ft_fabs((z1 + z2) / 2);
	rgb[fdf->settings.main_color] = 255 * z /
		(fdf->map.z_max * ft_fabs(fdf->settings.depth));
	return (rgb[2] + rgb[1] * 256 + rgb[0] * 256 * 256);
}

static void		ft_draw_pixel(int x, int y, int color, t_fdf *fdf)
{
	int		offset;

	x += fdf->settings.margin_left;
	y += fdf->settings.margin_top;
	if (x > 0 && x < W && y > 0 && y < H)
	{
		offset = y * fdf->mlx.img.size_line + x * (fdf->mlx.img.bpp / 8);
		*((int*)(fdf->mlx.img.data + offset)) = color;
	}
}

static void		ft_draw_line(t_xyz xyz, t_fdf *fdf)
{
	int	x;
	int	color;

	x = xyz.x1;
	color = ft_get_color(xyz.z1, xyz.z2, fdf);
	while (x++ < xyz.x2)
		ft_draw_pixel(x, xyz.y1 + ((xyz.y2 - xyz.y1) * (x - xyz.x1)) /
			(xyz.x2 - xyz.x1), color, fdf);
	while (x-- > xyz.x2)
		ft_draw_pixel(x, xyz.y1 + ((xyz.y2 - xyz.y1) * (x - xyz.x1)) /
			(xyz.x2 - xyz.x1), color, fdf);
}

static void		ft_draw_line_2(t_xyz xyz, t_fdf *fdf)
{
	int	y;
	int	color;

	y = xyz.y1;
	color = ft_get_color(xyz.z1, xyz.z2, fdf);
	while (y++ < xyz.y2)
		ft_draw_pixel(xyz.x1 + ((xyz.x2 - xyz.x1) * (y - xyz.y1)) /
			(xyz.y2 - xyz.y1), y, color, fdf);
	while (y-- > xyz.y2)
		ft_draw_pixel(xyz.x1 + ((xyz.x2 - xyz.x1) * (y - xyz.y1)) /
			(xyz.y2 - xyz.y1), y, color, fdf);
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
			ft_draw_line(xyz, fdf);
		else
			ft_draw_line_2(xyz, fdf);
	}
	if (y + 1 < fdf->map.nb_line)
	{
		xyz.z2 = fdf->map.matrix[y + 1][x] * fdf->settings.depth;
		xyz.y2 = (y - x + 1) * fdf->settings.y_scale - xyz.z2;
		if (ft_fabs(xyz.x2 - xyz.x1) > ft_fabs(xyz.y2 - xyz.y1))
			ft_draw_line(xyz, fdf);
		else
			ft_draw_line_2(xyz, fdf);
	}
}

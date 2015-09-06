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

static void		ft_draw_line_1(int x1, int y1, int x2, int y2, t_mlx mlx)
{
	int		x;
	int		y;

	x = x1;
	y = y1;
	while (x < x2)
	{
		mlx_pixel_put(mlx.mlx, mlx.win, x, y, 0xffffff);
		x += 1;
		y += y2 - y < 0 ? -1 : 1;
	}
}

static void		ft_draw_line_2(int x1, int y1, int x2, int y2, t_mlx mlx)
{
	int		x;
	int		y;

	x = x1;
	y = y1;
	while (y < y2)
	{
		mlx_pixel_put(mlx.mlx, mlx.win, x, y, 0xffffff);
		y += 1;
		x += x2 - x <= 0 ? -1 : 1;
	}
}

void			ft_draw(int x, int y, t_fdf *fdf)
{
	int		x1;
	int		x2;
	int		y1;
	int		y2;

	x1 = (x) * SCALE + MARGIN;
	x2 = (x + 1) * SCALE + MARGIN;
	y1 = (y) * SCALE - fdf->map.matrix[y][x] + MARGIN;
	y2 = (y) * SCALE - fdf->map.matrix[y][x + 1] + MARGIN;
	ft_draw_line_1(x1, y1, x2, y2, fdf->mlx);

	x1 = (x) * SCALE + MARGIN + fdf->map.matrix[y][x];
	x2 = (x) * SCALE + MARGIN + fdf->map.matrix[y + 1][x];
	y1 = (y) * SCALE + MARGIN;
	y2 = (y + 1) * SCALE + MARGIN;
	ft_draw_line_2(x1, y1, x2, y2, fdf->mlx);
}

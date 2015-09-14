/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 14:37:58 by gsaynac           #+#    #+#             */
/*   Updated: 2015/09/14 11:03:21 by gsaynac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		ft_process(t_fdf *fdf)
{
	int		x;
	int		y;

	y = 0;
	while (y < fdf->map.nb_line)
	{
		x = 0;
		while (x < fdf->map.nb_column)
		{
			ft_draw(x, y, fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->mlx.img.img, 0, 0);
}

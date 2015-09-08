/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 14:37:58 by gsaynac           #+#    #+#             */
/*   Updated: 2015/09/06 14:38:00 by gsaynac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		ft_process(t_fdf *fdf)
{
	size_t		x;
	size_t		y;

	y = 0;
	while (y < fdf->map.nb_line - 1)
	{
		x = 0;
		while (x < fdf->map.nb_column - 1)
		{
			ft_draw(x, y, fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->mlx.img.img, 0, 0);
}
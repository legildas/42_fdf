/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 15:52:38 by gsaynac           #+#    #+#             */
/*   Updated: 2015/09/14 10:58:34 by gsaynac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		ft_clear_image(t_fdf *fdf)
{
	int		i;
	int		j;
	int		offset;

	i = 0;
	while (i < H)
	{
		j = 0;
		while (j < W)
		{
			offset = i * fdf->mlx.img.size_line + j * (fdf->mlx.img.bpp / 8);
			*((int*)(fdf->mlx.img.data + offset)) = 0x000000;
			j++;
		}
		i++;
	}
}

void		ft_mlx_init(t_fdf *fdf)
{
	if (!(fdf->mlx.mlx = mlx_init()))
		ft_error("failed to init mlx");
	if (!(fdf->mlx.win = mlx_new_window(fdf->mlx.mlx, W, H, "fdf")))
		ft_error("failed to create new window");
	if (!(fdf->mlx.img.img = mlx_new_image(fdf->mlx.mlx, W, H)))
		ft_error("failed to create new image");
	if (!(fdf->mlx.img.data = mlx_get_data_addr(fdf->mlx.img.img,
		&fdf->mlx.img.bpp, &fdf->mlx.img.size_line, &fdf->mlx.img.endian)))
		ft_error("failed to get image datas");
	mlx_key_hook(fdf->mlx.win, ft_key_hook, fdf);
	mlx_mouse_hook(fdf->mlx.win, ft_mouse_hook, fdf);
	mlx_expose_hook(fdf->mlx.win, ft_expose_hook, fdf);
}

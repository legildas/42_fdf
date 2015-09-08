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

void		ft_set_settings(t_fdf *fdf)
{
	fdf->settings.y_scale = H / fdf->map.nb_line / 2;
	fdf->settings.x_scale = W / fdf->map.nb_column / 2;
	fdf->settings.margin_left = ((W / 2) - (fdf->map.nb_column * fdf->settings.x_scale / 2)) / 2;
	fdf->settings.margin_top = (H / 2) - (fdf->map.nb_line * fdf->settings.y_scale / 2);
	fdf->settings.depth = 1;
}
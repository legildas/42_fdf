/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 15:07:37 by gsaynac           #+#    #+#             */
/*   Updated: 2015/08/26 18:01:39 by gsaynac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int				main(int ac, char **av)
{
	t_fdf		fdf;

	(void)ac;
	if (ac != 2)
		ft_error("missing map");
	else
	{
		ft_parse(av[1], &fdf);
		ft_mlx_init(&fdf);
	}
	return (1);
}

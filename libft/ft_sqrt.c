/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 18:22:01 by gsaynac           #+#    #+#             */
/*   Updated: 2015/01/27 20:07:50 by gsaynac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

double		ft_sqrt(double x)
{
	double		i;
	double		diff;
	double		close_enough;

	if (x < 0)
		return (0);
	i = x;
	close_enough = 1;
	while (i > 0)
	{
		diff = ft_fabs(i * i - x);
		if (diff < ft_fabs(close_enough * close_enough - x))
			close_enough = i;
		if (diff == 0)
			return (i);
		i -= 0.001;
	}
	return (close_enough);
}

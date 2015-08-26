/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 14:53:10 by gsaynac           #+#    #+#             */
/*   Updated: 2015/01/27 17:48:18 by gsaynac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

double		ft_max(double *x, size_t size)
{
	double			res;
	unsigned int	i;

	res = x[0];
	i = 0;
	while (i < size)
	{
		if (x[i] > res)
		{
			res = x[i];
		}
		i++;
	}
	return (res);
}

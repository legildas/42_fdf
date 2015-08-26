/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 17:19:20 by gsaynac           #+#    #+#             */
/*   Updated: 2015/08/20 17:35:19 by gsaynac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putcat(int n, ...)
{
	va_list		va;
	int			i;

	va_start(va, n);
	i = 0;
	while (i < n)
	{
		ft_putstr(va_arg(va, char*));
		i++;
	}
	va_end(va);
}

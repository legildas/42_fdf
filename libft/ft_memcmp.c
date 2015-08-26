/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:12:06 by gsaynac           #+#    #+#             */
/*   Updated: 2015/01/26 19:41:02 by gsaynac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*tmp;
	const unsigned char		*tmp2;

	tmp = (const unsigned char*)s1;
	tmp2 = (const unsigned char*)s2;
	while (n-- && *tmp++ == *tmp2++)
	{
		if (!n)
			return (0);
	}
	return (*--tmp - *--tmp2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:50:06 by gsaynac           #+#    #+#             */
/*   Updated: 2015/01/26 19:41:02 by gsaynac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*s1;

	s1 = (const unsigned char *)s;
	while (n--)
	{
		if (*s1++ == (unsigned char)c)
			return ((void *)--s1);
	}
	return (NULL);
}

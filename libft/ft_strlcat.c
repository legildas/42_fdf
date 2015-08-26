/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:24:13 by gsaynac           #+#    #+#             */
/*   Updated: 2015/01/26 19:40:57 by gsaynac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dst2;
	const char	*src2;
	size_t		n;
	size_t		len;

	dst2 = dst;
	src2 = src;
	n = size;
	while (n-- && *dst2)
		dst2++;
	len = dst2 - dst;
	n = size - len;
	if (n == 0)
		return (len + ft_strlen(src));
	while (n-- > 1 && *src2)
		*dst2++ = *src2++;
	*dst2 = '\0';
	return (len + ft_strlen(src));
}

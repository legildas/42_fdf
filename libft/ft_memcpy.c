/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:18:58 by gsaynac           #+#    #+#             */
/*   Updated: 2015/01/26 19:41:02 by gsaynac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char		*tmp1;
	const unsigned char	*tmp2;

	tmp1 = (unsigned char*)s1;
	tmp2 = (const unsigned char*)s2;
	while (n--)
		*tmp1++ = *tmp2++;
	return (s1);
}

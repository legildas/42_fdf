/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:28:47 by gsaynac           #+#    #+#             */
/*   Updated: 2015/01/26 19:41:01 by gsaynac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	s3[n];

	ft_memcpy((void *)s3, s2, n);
	ft_memcpy(s1, (const void *)s3, n);
	return (s1);
}

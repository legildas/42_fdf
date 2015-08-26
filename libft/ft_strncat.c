/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:33:46 by gsaynac           #+#    #+#             */
/*   Updated: 2015/01/26 19:40:56 by gsaynac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char		*tmp;

	tmp = s1 + ft_strlen(s1);
	while (*s2 && n--)
		*tmp++ = *s2++;
	*tmp = '\0';
	return (s1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 10:12:10 by gsaynac           #+#    #+#             */
/*   Updated: 2015/01/26 19:40:54 by gsaynac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	if (!*s2)
		return ((char*)s1);
	i = 0;
	while (s1[i] && i < n)
	{
		j = 0;
		while (s2[j] && (i + j) < n)
		{
			if (s1[i + j] != s2[j] || !s2[j])
				break ;
			j++;
		}
		if (!s2[j])
			return (i + (char*)s1);
		i++;
	}
	return (NULL);
}

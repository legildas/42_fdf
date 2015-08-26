/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 09:29:16 by gsaynac           #+#    #+#             */
/*   Updated: 2015/01/26 19:40:54 by gsaynac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char			*ft_strstr(const char *s1, const char *s2)
{
	int			i;
	int			j;

	if (!*s2)
		return ((char*)s1);
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
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

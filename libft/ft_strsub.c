/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 22:02:30 by gsaynac           #+#    #+#             */
/*   Updated: 2015/01/26 19:40:53 by gsaynac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*tmp;

	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	tmp = str;
	while (len--)
		*tmp++ = s[start++];
	*tmp = '\0';
	return (str);
}

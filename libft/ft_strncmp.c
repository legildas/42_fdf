/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 10:58:24 by gsaynac           #+#    #+#             */
/*   Updated: 2015/01/26 19:40:55 by gsaynac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*u_s1;
	unsigned char	*u_s2;

	i = 0;
	u_s1 = (unsigned char*)s1;
	u_s2 = (unsigned char*)s2;
	while (u_s1[i] == u_s2[i] && u_s1[i] && u_s2[i] && i < n)
		i++;
	if (s1[i - 1] == s2[i - 1] && (i == n || (u_s1[i] == u_s2[i])))
		return (0);
	return (u_s1[i] - u_s2[i]);
}

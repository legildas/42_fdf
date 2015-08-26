/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 07:08:16 by gsaynac           #+#    #+#             */
/*   Updated: 2015/01/26 19:40:53 by gsaynac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtrim(char const *s)
{
	char		*tmp;
	char		*tmp2;
	char		*s2;
	size_t		i;

	i = 0;
	if (s == NULL)
		return (0);
	if ((tmp = ft_strdup(s)) == NULL)
		return (NULL);
	while (tmp[i] == ' ' || tmp[i] == '\n' || tmp[i] == '\t')
		++i;
	if ((tmp2 = ft_strdup((const char*)tmp + i)) == NULL)
		return (NULL);
	i = ft_strlen(tmp2) - 1;
	while (tmp2[i] == ' ' || tmp2[i] == '\n' || tmp2[i] == '\t')
		--i;
	tmp2[i + 1] = '\0';
	if ((s2 = ft_strdup((const char*)tmp2)) == NULL)
		return (NULL);
	free(tmp);
	free(tmp2);
	return (s2);
}

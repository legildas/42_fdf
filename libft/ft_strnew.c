/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 22:06:53 by gsaynac           #+#    #+#             */
/*   Updated: 2015/01/26 19:40:55 by gsaynac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnew(size_t size)
{
	char	*s;

	if ((s = (char*)malloc(sizeof(*s) * (size + 1))) == NULL)
		return (NULL);
	ft_bzero(s, size + 1);
	return (s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 21:15:58 by gsaynac           #+#    #+#             */
/*   Updated: 2015/01/26 19:41:03 by gsaynac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list			*map;
	t_list			*add;
	t_list			*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	map = f(lst);
	tmp = map;
	lst = lst->next;
	while (lst != NULL)
	{
		add = f(lst);
		if (add == NULL)
			return (NULL);
		tmp->next = add;
		tmp = add;
		lst = lst->next;
	}
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 21:24:03 by gsaynac           #+#    #+#             */
/*   Updated: 2015/01/27 22:06:15 by gsaynac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static t_gnl		*get_gnl(int const fd)
{
	static t_gnl	*gnlfd_list = NULL;
	t_gnl			*tmp;

	tmp = gnlfd_list;
	while (tmp != NULL)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if ((tmp = (t_gnl*)malloc(sizeof(t_gnl))) == NULL)
		return (NULL);
	*tmp = (t_gnl){NULL, fd, gnlfd_list};
	gnlfd_list = tmp;
	return (tmp);
}

static int			ft_process_buf(char **remain, char *buf, char **line)
{
	char			*keep;
	char			*tmp;
	unsigned int	len;

	tmp = *line;
	if ((*remain = ft_strchr(buf, '\n')) != NULL)
	{
		len = ft_strlen(buf) - ft_strlen(*remain);
		*remain = ft_strsub(buf, len, ft_strlen(*remain)) + 1;
		keep = ft_strsub(buf, 0, len);
		*line = ft_strjoin(tmp, keep);
		free(tmp);
		free(keep);
		return (1);
	}
	*line = ft_strjoin(tmp, buf);
	free(tmp);
	return (0);
}

static char			*ft_remain(char **line, char *remain)
{
	char	*tmp;
	int		size;

	tmp = remain;
	if ((tmp = ft_strchr(remain, '\n')) != NULL)
	{
		*tmp = '\0';
		size = ft_strlen(remain);
		*tmp = '\n';
		*line = ft_strsub(remain, 0, size);
		return (remain + size);
	}
	*line = ft_strdup(remain);
	return (remain + ft_strlen(remain));
}

int					get_next_line(int const fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	t_gnl			*gnl;

	if (fd < 0 || !line || !(gnl = get_gnl(fd)))
		return (-1);
	*line = ft_strnew(sizeof(char*));
	if (gnl->remain)
	{
		gnl->remain = ft_remain(line, gnl->remain);
		if (*gnl->remain == '\n')
		{
			gnl->remain++;
			return (1);
		}
	}
	while ((ret = read(gnl->fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		if ((ft_process_buf(&(gnl->remain), buf, line)) == 1)
			return (1);
	}
	return (0);
}

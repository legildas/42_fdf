/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/05 16:13:55 by gsaynac           #+#    #+#             */
/*   Updated: 2015/09/05 16:13:58 by gsaynac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int		ft_get_fd(char *filename)
{
	int		fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_error("invalid filename");
	return (fd);
}

static void		ft_get_size(char *filename, t_map *map)
{
	char	**parsed_line;
	char	*buffer;
	int		fd;
	size_t	len;

	fd = ft_get_fd(filename);
	while (get_next_line(fd, &buffer))
	{
		map->nb_line++;
		parsed_line = ft_strsplit(buffer, ' ');
		len = -1;
		while (parsed_line[++len])
			free(parsed_line[len]);
		if (map->nb_column != len)
		{
			if (!map->nb_column)
				map->nb_column = len;
			else
				ft_error("unconsistent column length");
		}
		free(parsed_line);
		free(buffer);
	}
	close(fd);
}

static void		ft_malloc_map(t_map *map)
{
	size_t		i;

	map->matrix = malloc(map->nb_line * sizeof(*map->matrix));
	i = 0;
	while (i < map->nb_line)
		map->matrix[i++] = malloc(map->nb_column * sizeof(**map->matrix));
}

static void		ft_read_map(char *filename, t_map *map)
{
	char	**parsed_line;
	char	*buffer;
	int		fd;
	int		i;
	int		j;

	fd = ft_get_fd(filename);
	i = 0;
	while (get_next_line(fd, &buffer))
	{
		parsed_line = ft_strsplit(buffer, ' ');
		j = 0;
		while (parsed_line[j])
		{
			map->matrix[i][j] = ft_atoi(parsed_line[j]);
			free(parsed_line[j]);
			j++;
		}
		free(parsed_line);
		free(buffer);
		i++;
	}
	close(fd);
}

void			ft_parse(char *filename, t_fdf *fdf)
{
	fdf->map.nb_line = 0;
	fdf->map.nb_column = 0;
	ft_get_size(filename, &fdf->map);
	ft_malloc_map(&fdf->map);
	ft_read_map(filename, &fdf->map);
}

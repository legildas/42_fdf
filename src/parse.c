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

static void		ft_process_buffer(char *buffer, t_map *map, int i, int to_data)
{
	char	**parsed_line;
	size_t	j;

	parsed_line = ft_strsplit(buffer, ' ');
	j = 0;
	while (parsed_line[j])
	{
		if (to_data)
			map->matrix[i][j] = ft_atoi(parsed_line[j]);
		if (to_data && map->z_max < ft_fabs(map->matrix[i][j]))
			map->z_max = ft_fabs(map->matrix[i][j]);
		free(parsed_line[j]);
		j++;		
	}
	if (!to_data)
	{
		map->nb_line++;
		if (map->nb_column != j)
		{
			if (!map->nb_column)
				map->nb_column = j;
			else
				ft_error("unconsistent column length");
		}		
	}
	free(parsed_line);
	free(buffer);
}

static void		ft_read_map(char *filename, t_map *map, int to_data)
{
	char	*buffer;
	int		fd;
	int		i;

	i = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_error("invalid filename");
	while (get_next_line(fd, &buffer) > 0)
		ft_process_buffer(buffer, map, i++, to_data);
	if (ft_strlen(buffer))
		ft_process_buffer(buffer, map, i++, to_data);
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

void			ft_parse(char *filename, t_fdf *fdf)
{
	fdf->map.nb_line = 0;
	fdf->map.nb_column = 0;
	fdf->map.z_max = 0;
	ft_read_map(filename, &fdf->map, 0);
	ft_malloc_map(&fdf->map);
	ft_read_map(filename, &fdf->map, 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 15:08:20 by gsaynac           #+#    #+#             */
/*   Updated: 2015/08/26 18:01:01 by gsaynac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define W					1920
# define H					1080

# define KEY_ESCAPE			53

# define SCALE				20
# define DEPTH				5
# define MARGIN				500

# include <libft.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct				s_mlx
{
	void					*mlx;
	void					*win;
}							t_mlx;

typedef struct				s_map
{
	size_t					nb_line;
	size_t					nb_column;
	int						**matrix;
}							t_map;

typedef struct				s_fdf
{
	t_mlx					mlx;
	t_map					map;
}							t_fdf;

void						ft_mlx_init(t_fdf *fdf);
void						ft_error(char *error);
void						ft_parse(char *filename, t_fdf *fdf);
void						ft_process(t_fdf *fdf);
void						ft_draw(int x, int y, t_fdf *fdf);

#endif
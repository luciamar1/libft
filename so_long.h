/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:47:49 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/06/28 16:34:37 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "mlx/minilibx-linux/mlx.h"
# include "mlx/minilibx-linux/mlx_int.h"
# include "libft/libft.h"

#ifndef COLORS_H

# define COLORS_H

/* Color codes for printf  */
# define DEFAULT "\033[0;39m"
# define GRAY "\033[0;90m"
# define RED "\033[0;91m"
# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"
# define BLUE "\033[0;94m"
# define MAGENTA "\033[0;95m"
# define CYAN "\033[0;96m"
# define WHITE "\033[0;97m"

#endif

typedef struct s_map_list
{
	int	x;
	int	y;
	struct	s_map_list	*next;	
}	t_map_list;

typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;


typedef struct	s_map
{
	char	n_exits;
	char	n_inits;
	char	n_objects;
	char	**map_copy;
	t_vector	P;
	t_vector	E;

	int		x;
	int		y;
}	t_map;


typedef struct	s_window {
	void		*reference;
	t_vector	size;
}				t_window;

typedef struct	s_image {
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct	s_minilib
 {
	void	*mlx_pointer;
	t_window	*window;
	t_image		sprite;
	t_vector	sprite_position;
	// … etc
}				t_minilib;

char	**check_file(int argc, char **argv, t_map *map);
void	return_error(char *message, char **map);
char    **check_map(int argc, char **argv, int fd, t_map *map);
void	validate_path(t_map *map, int y, int x);


#endif
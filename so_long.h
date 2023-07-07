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

#include "colors.h"
#include "game.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "mlx/minilibx-linux/mlx.h"
# include "mlx/minilibx-linux/mlx_int.h"
# include "libft/libft.h"

# define SIZE 32


typedef struct	s_map
{
	char	n_exits;
	char	n_inits;
	char	n_objects;
	char	**map_copy;
	char	**map_real;
	t_vector	P;
	t_vector	E;

	int		columns;
	int		rows;
}	t_map;


//   check functions

char	**check_file(int argc, char **argv, t_map *map);
void	return_error(char *message, char **map);
char    **check_map(int argc, char **argv, int fd, t_map *map);
void	validate_path(t_map *map, int y, int x, int *ob);

// game_basic  functions
int    start_game(t_map *map, t_minilib *program);




#endif
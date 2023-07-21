/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:47:49 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/07/21 23:43:54 by lucia-ma         ###   ########.fr       */
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
// # include "mlx/minilibx-linux/mlx.h"
// # include "mlx/minilibx-linux/mlx_int.h"
#include "./mlx/mlx.h"
# include "libft/libft.h"

# define SIZE 32

typedef struct	s_position_to_paint
{
	int	x;
	int	y;
}	t_position_to_paint;

typedef struct	s_map
{
	char	n_exits;
	char	n_inits;
	char	n_objects;
	char	**map_copy;
	char	**map_real;
	t_minilib	*program;
	t_vector	P;
	t_vector	E;
	t_position_to_paint	position_to_paint;
	int		columns;
	int		rows;
}	t_map;


//   check functions

char	**checker(int argc, char **argv, t_map *map);
void	return_error(char *message, char **map);
char    **check_map(int argc, char **argv, int fd, t_map *map);
void	validate_path(t_map *map, int y, int x, int *ob);

// game_basic  functions
int    start_game(t_map *map);




#endif
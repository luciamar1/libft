/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:47:49 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/07/24 18:24:02 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "game.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
//////////LINUX//////////////
// # include "mlx/minilibx-linux/mlx.h"
// # include "mlx/minilibx-linux/mlx_int.h"
//////////LINUX//////////////

////////// MAC////////////
# include "./mlx/mlx.h"
//////////MAC////////////
# include "libft/libft.h"

# define SIZE 32

typedef struct s_position_to_paint
{
	int	x;
	int	y;
}	t_position_to_paint;

typedef struct s_map
{
	int					n_exits;
	int					n_inits;
	int					n_objects;
	char				**map_copy;
	char				**map_real;
	t_minilib			program;
	t_vector			p;
	t_vector			e;
	t_position_to_paint	pos_to_paint;
	int					columns;
	int					rows;
}	t_map;

//   check functions
int		ft_strchr_so_long(char *s, t_map *map);
int		checker(int argc, char **argv, t_map *map);
void	return_error(char *message, char *map_str, char **map_bi);
char	**check_map(int argc, char **argv, int fd, t_map *map);
void	validate_path(t_map *map, int y, int x, int *ob);
char	**create_map(char **map, char **map_str);
int		create_map_str(int fd, t_map *map, char **map_str);
int		validate_len(char **map, t_map *map_list);
int		rec_up_down(char **map, int len, int *x);
int		validate_structure(char **map, t_map *map_list);

// game_basic  functions
int		start_game(t_map *map);
void	move_al_uranio(int key, t_map *map, int *vector);
int		key_hook(int key, t_map *map);
void	close_game(t_map *map, int win);

#endif
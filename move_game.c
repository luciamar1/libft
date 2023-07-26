/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:47:49 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/07/26 19:00:46 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sticker(t_map *map, char *array, int x, int y)
{
	int	*img;
	int	size;

	size = SIZE;
	img = mlx_xpm_file_to_image(map->program.mlx_pointer, array, &size, &size);
	mlx_put_image_to_window(map->program.mlx_pointer, map->program.window, img, \
		(x) * 32, (y) * 32);
	mlx_destroy_image(map->program.mlx_pointer, img);
}

void	vector_mov(int *x, int *y, int key)
{
	if (key == 0)
		*x = -1;
	if (key == 2)
		*x = +1;
	if (key == 1)
		*y = +1;
	if (key == 13)
		*y = -1;
}

int	key_hook(int key, t_map *map)
{
	int			vector[2];
	int			parx;
	int			pary;

	vector[1] = ((vector[0] = 0), 0);
	vector_mov(&vector[0], &vector[1], key);
	parx = map->program.p.x + vector[0];
	pary = map->program.p.y + vector[1];
	if (map->map_real[pary][parx] == 'C')
		map->map_real[pary][parx] = ((map->n_objects --), '0');
	if (map->n_objects == 0)
		sticker(map, "./sprites/puerta2.xpm", \
			map->program.e.x, map->program.e.y);
	if (map->map_real[pary][parx] == 'E' && map->n_objects == 0)
	{
		move_al_uranio(map, vector);
		close_game(map, 0);
	}
	if (key == 53)
		close_game(map, 1);
	else if ((key == 0 || key == 1 || key == 2 || key == 13) \
		&& map->map_real[pary][parx] != '1' )
		move_al_uranio(map, vector);
	return (0);
}

void	move_al_uranio(t_map *map, int *vector)
{
	int			size;
	static int	counter = 1;

	size = SIZE;
	ft_printf("number of movements  ==  %d\n", counter);
	counter ++;
	if (map->map_real[map->program.p.y][map->program.p.x] == 'E')
	{
		sticker(map, "./sprites/Pink_Monster_Run_6.xpm", \
			map->program.p.x + vector[0], map->program.p.y + vector[1]);
		sticker(map, "./sprites/puerta1.xpm", map->program.p.x, \
			map->program.p.y);
	}
	else
	{
		sticker(map, "./sprites/Pink_Monster_Run_6.xpm", \
			map->program.p.x + vector[0], map->program.p.y + vector[1]);
		sticker(map, "./sprites/fondo.xpm", map->program.p.x, map->program.p.y);
	}
	map->program.p.x += vector[0];
	map->program.p.y += vector[1];
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_basics_mac.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:47:49 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/07/24 18:10:53 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image2(t_map *map, int x, int y, void *img)
{
	int		size;

	size = SIZE;
	if (map->map_real[y][x] == '1')
		img = mlx_xpm_file_to_image(map->program.mlx_pointer, \
			"./sprites/bloque.xpm", &size, &size);
	if (map->map_real[y][x] == '0')
		img = mlx_xpm_file_to_image(map->program.mlx_pointer, \
			"./sprites/fondo.xpm", &size, &size);
	if (map->map_real[y][x] == 'C')
		img = mlx_xpm_file_to_image(map->program.mlx_pointer, \
			"./sprites/pineaple.xpm", &size, &size);
	mlx_put_image_to_window(map->program.mlx_pointer, map->program.window, \
		img, x * 32, y * 32);
	mlx_destroy_image(map->program.mlx_pointer, img);
}

void	put_image(t_map *map, int x, int y)
{
	void	*img;
	int		size;

	size = SIZE;
	if (map->map_real[y][x] == 'P')
	{
		map->program.p.y = ((map->program.p.x = x), y);
		img = mlx_xpm_file_to_image(map->program.mlx_pointer, \
			"./sprites/Pink_Monster_Run_6.xpm", &size, &size);
	}
	if (map->map_real[y][x] == 'E')
	{
		map->program.e.y = ((map->program.e.x = x), y);
		img = mlx_xpm_file_to_image(map->program.mlx_pointer, \
			"./sprites/puerta1.xpm", &size, &size);
	}
	put_image2(map, x, y, img);
}

void	close_game(t_map *map, int win)
{
	if (win == 0)
		write(1, "\n\nYUHUUUUUUU SOY LIBREEEE!!!\n\n      GRACIAS =)\n\n", 49);
	else
		write(1, "ooooyyyyeeee no me cierres =(\n", 30);
	mlx_destroy_window(map->program.mlx_pointer, map->program.window);
	free(map->program.mlx_pointer);
	ft_freecharmatrix(map->map_real);
	exit(0);
}

/* ************************************************************************** */
int	start_game(t_map *map)
{
	int		size;

	map->pos_to_paint.y = ((map->pos_to_paint.x = 0), (size = SIZE), 0);
	map->program.mlx_pointer = mlx_init();
	if (!map->program.mlx_pointer)
		return (return_error("mlx_init fail\n", NULL, map->map_real), 1);
	map->program.window = mlx_new_window(map->program.mlx_pointer, \
		map->columns * SIZE, map->rows * SIZE, "Hellow minilib =)");
	if (!map->program.window)
		return (((return_error("mlx_init fail\n", NULL, map->map_real)), \
			(free(map->program.mlx_pointer))), 1);
	while (map->map_real[map->pos_to_paint.y])
	{
		while (map->map_real[map->pos_to_paint.y][map->pos_to_paint.x])
		{
			put_image(map, map->pos_to_paint.x, map->pos_to_paint.y);
			map->pos_to_paint.x++;
		}
		map->pos_to_paint.x = ((map->pos_to_paint.y++), 0);
	}
	mlx_hook(map->program.window, 17, 1L << 17, key_hook, map);
	mlx_key_hook(map->program.window, key_hook, map);
	mlx_loop(map->program.mlx_pointer);
	return (0);
}

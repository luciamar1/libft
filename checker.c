/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:48:04 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/07/26 18:28:43 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_path(t_map *map, int y, int x, int	*ob)
{
	char	*p;

	p = &map->map_copy[y][x];
	if (*p != '1')
	{
		if (*p == 'C')
			*ob -= 1;
		if (*p == 'E')
			map->n_exits--;
		*p = '1';
		if (map->map_copy[y][x + 1] != '1')
			validate_path(map, y, x + 1, ob);
		if (map->map_copy[y][x - 1] != '1')
			validate_path(map, y, x - 1, ob);
		if (map->map_copy[y - 1][x] != '1')
			validate_path(map, y - 1, x, ob);
		if (map->map_copy[y + 1][x] != '1')
			validate_path(map, y + 1, x, ob);
	}
}

int	checker(int argc, char **argv, t_map *map)
{
	int		fd;
	char	**map_bi;

	if (argc != 2)
		return (return_error("the number of arguments is wrong =(", \
			NULL, NULL), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (return_error("the file can't be open =(", NULL, NULL), 1);
	if (ft_str_rev_n_cmp(argv[1], ".ber", 4) != 0)
		return (return_error("the file is not .ber =(", NULL, NULL), 1);
	map_bi = check_map(fd, map);
	if (map_bi == NULL)
		return (return_error("the map is wrong =(", NULL, NULL), 1);
	return (0);
}

int	ft_strchr_so_long(char *s, t_map *map)
{
	while (*s)
	{
		if (*s == 'E')
			map->n_exits = map->n_exits + 1;
		if (*s == 'C')
			map->n_objects = map->n_objects + 1;
		if (*s == 'P')
			map->n_inits = map->n_inits + 1;
		if (*s != 'E' && *s != 'C' && *s != 'P' && *s != '1' && *s != '0' \
			&& *s != '\n')
			return (1);
		s++;
	}
	return (0);
}

void	position_p(char **map_bi, t_map *map)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (map_bi[y])
	{
		while (map_bi[y][x])
		{
			if (map_bi[y][x] == 'P')
			{
				map->p.y = y;
				map->p.x = x;
			}
			x++;
		}
		x = 0;
		y ++;
	}
}

char	**check_map(int fd, t_map *map)
{
	char	*map_str;
	char	**map_bi;
	int		ob;

	map->n_objects = ((map->n_exits = 0), (map->n_inits = 0), 0);
	map_str = NULL;
	map_bi = NULL;
	if (create_map_str(fd, map, &map_str) == 1)
		return (NULL);
	map_bi = create_map(map_bi, &map_str);
	if (validate_structure(map_bi, map) == 1)
		return ((return_error("invalid map\n", NULL, map_bi)), NULL);
	position_p(map_bi, map);
	map->map_copy = ft_strdup_array_bi(map_bi);
	if (map->map_copy == NULL)
		return ((return_error("creation of map_copy fail\n", \
			NULL, map_bi)), NULL);
	map->map_real = map_bi;
	ob = map->n_objects;
	validate_path(map, map->p.y, map->p.x, &ob);
	if (ob > 0 || map->n_exits == 1)
		return (NULL);
	return (map_bi);
}

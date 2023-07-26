/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:48:04 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/07/26 18:30:09 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_map(char **map, char **map_str)
{
	map = ft_split(*map_str, '\n');
	if (map == NULL)
	{
		return_error("split fail", *map_str, NULL);
		return (NULL);
	}
	else
		free(*map_str);
	return (map);
}

int	create_map_str(int fd, t_map *map, char **map_str)
{
	char	*line_map;
	int		counter;

	while (1)
	{
		counter = 0;
		line_map = get_next_line(fd);
		if (!line_map)
			break ;
		if (ft_strchr_so_long(line_map, map) == 1)
		{
			map->n_inits = -1;
			break ;
		}
		*map_str = ft_strjoin_chetao(map_str, &line_map);
	}
	if (map->n_exits != 1 || map->n_inits != 1 || map->n_objects < 1)
		return ((return_error("invalid map", *map_str, NULL)), 1);
	return (0);
}

int	validate_len(char **map, t_map *map_list)
{
	int	y;
	int	x;
	int	len;

	y = 0;
	x = 0;
	len = ft_strlen(map[y++]);
	while (map[y] && ft_strlen(map[y]) == (size_t)len)
	{
		y ++;
	}
	if (map[y] || y > 5120 || x > 2880)
		return (1);
	if (y == len)
		return (1);
	map_list->rows = y;
	map_list->columns = len;
	return (0);
}

int	rec_up_down(char **map, int len, int *x)
{
	while (map[0][*x])
		if (map[0][(*x)++] != '1')
			return (1);
	*x = 0;
	while (map[len][*x])
		if (map[len][(*x)++] != '1')
			return (1);
	return (0);
}

int	validate_structure(char **map, t_map *map_list)
{
	int	y;
	int	x;
	int	len;
	int	l ;

	x = ((y = 0), (len = 0), (l = 0), 0);
	if (validate_len(map, map_list) == 1)
		return (1);
	while (map[len])
		len ++;
	l = len;
	len -= 1;
	if ((rec_up_down(map, len, &x)) == 1)
		return (1);
	len ++;
	while (len --)
		if (map[y++][0] != '1')
			return (1);
	x --;
	y = 0;
	while (l--)
		if (map[y++][x] != '1')
			return (1);
	return (0);
}

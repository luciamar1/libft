/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:48:04 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/06/28 17:37:43 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_path(t_map *map, int y, int x)
{
	char	*p;

	p = &map->map_copy[y][x];
	if (*p != '1')
	{
		if (*p == 'C')
			map->n_objects--;
		*p = '1';
		if (map->map_copy[y][x + 1] != '1')
			validate_path(map, y, x + 1);
		if (map->map_copy[y][x - 1] != '1')
			validate_path(map, y, x - 1);
		if (map->map_copy[y - 1][x] != '1')
			validate_path(map, y - 1, x);
		if (map->map_copy[y + 1][x] != '1')
			validate_path(map, y + 1, x);
	}
}

void	return_error(char *message, char **map)
{
	if (map)
    {
		free(*map);
    }
    while(*message)
        write(1, message++, 1);
    write(1, "\n", 1);
}

char **check_file(int argc, char **argv, t_map *map)
{
    int fd;
    char **map_bi;
    if (argc != 2)
    {
        return_error("the number of arguments is wrong =(", NULL);
        return (NULL);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        return_error("the file can't be open =(", NULL);
        return (NULL);
    }
    if (ft_str_rev_n_cmp(argv[1], ".ber", 4) != 0)
    {
        return_error("the file is not .ber =(", NULL);
        return (NULL);
    }
    map_bi = check_map(argc, argv, fd, map);
    return (map_bi);
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
        if (*s != 'E'&& *s != 'C' && *s != 'P' && *s != '1' && *s != '0' && *s != '\n')
            return(1);
		s++;
	}
	return (0);
}

char **create_map(char **map, char **map_str)
{
    map = ft_split(*map_str, '\n');
    if(map == NULL)
    {
        return_error("split fail", map_str);
        return(NULL);
    }  
    free(*map_str);
    return(map);
}

int create_map_str(int fd, t_map *map, char **map_str)
{
    char    *line_map;
    int     counter;

    while(1)
    {
        counter = 0;
        line_map = get_next_line(fd);
        if(!line_map)
            break;
        if(ft_strchr_so_long(line_map, map) == 1)
        {
            free(line_map);
            map->n_inits = -1;
            break;
        }
        *map_str = ft_strjoin_chetao(map_str, &line_map);
    }
    if(map->n_exits != 1 || map->n_inits != 1 || map->n_objects < 1)
    {
        return_error("invalid map", map_str);
        return (1);
    }
    return (0);
}

int validate_len(char **map)
{
    int y;
    int x;
    int cant;
    int len;

    y = 0;
    x = 0;
    len = ft_strlen(map[y++]);
    while(map[y] && ft_strlen(map[y]) == len)
    {
        y ++;
    }
    if(map[y])
        return(1);
    if(y == ft_strlen(map[--y]))
        return(1);
    return(0);
}

int validate_structure(char **map)
{
    int y;
    int x;
    int cant;
    int len;
    int l ;

    y = 0;
    x = 0;
    len = 0;
    if(validate_len(map) == 1)
        return(1);
    l = len;
    while(map[len])
        len ++;
    len -= 1;
    while(map[0][x])
        if(map[0][x++] != '1')
            return(1);  
    x = 0;
    while(map[len][x])
    {
        if(map[len][x++] != '1')
            return(1);
    }
    len ++;
    while(len --)
    {
        if(map[y++][0] != '1')
            return(1);
    }
    y = 0;
    x --;
    while(l--)
    {
        if(map[y++][x] != '1')
            return(1);
    }
    return(0);
}

void position_p(char **map_bi, t_map *map)
{
    int y;
    int x;

    x = 0;
    y = 0;
    while(map_bi[y])
    {
        while(map_bi[y][x])
        {

            if(map_bi[y][x] == 'P')
            {
                map->P.y = y;
                map->P.x = x;
            }
            x++;
            
        }
        x = 0;
        y ++;
    }
}

char    **check_map(int argc, char **argv, int fd, t_map *map)
{
    char    *map_str;
    char    **map_bi;
    char    *old_line_map;
    int     counter = 0;

    map->n_exits = 0;
    map->n_inits = 0;
    map->n_objects = 0;
    map_str = NULL;
    if(create_map_str(fd, map, &map_str) == 1)
        return(NULL);
    map_bi = create_map(map_bi, &map_str);
    if(validate_structure(map_bi) == 1)
    {
        write(1, "invalid map\n", 12);
        ft_freecharmatrix(map_bi);
        return(NULL);
    }    
    map->map_copy = map_bi;
    position_p(map_bi, map);
	while(map_bi[counter])
	{
		map->map_copy[counter] = ft_strdup(map_bi[counter]);
		counter ++;
	}
    validate_path(map, map->P.y, map->P.x);
    if(map->n_objects > 0)
        return(NULL);
    return (map_bi);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:48:04 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/07/21 23:47:10 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_path(t_map *map, int y, int x, int *ob)
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

void	return_error(char *message, char *map_str, char **map_bi)
{
	if (map_str)
		free(map_str);
    if (map_bi)
        ft_freecharmatrix(map_bi);
    while(*message)
        write(1, message++, 1);
    write(1, "\n", 1);
}

int checker(int argc, char **argv, t_map *map)
{
    int fd;
    char **map_bi;
    if (argc != 2)
        return (return_error("the number of arguments is wrong =(", NULL, NULL), 1);
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return (return_error("the file can't be open =(", NULL, NULL), 1);
    if (ft_str_rev_n_cmp(argv[1], ".ber", 4) != 0)
        return (return_error("the file is not .ber =(", NULL, NULL), 1);
    map_bi = check_map(argc, argv, fd, map);
    if(map_bi == NULL)
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
        if (*s != 'E' && *s != 'C' && *s != 'P' && *s != '1' && *s != '0' && *s != '\n')
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
        return_error("split fail", *map_str, NULL);
        return(NULL);
    }  
    else
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
        printf("while map_str == %s\n", *map_str);
    }
    if(map->n_exits != 1 || map->n_inits != 1 || map->n_objects < 1)
        return ((return_error("invalid map", *map_str, NULL)), 1);
    return (0);
}

int validate_len(char **map, t_map *map_list)
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
    if(y == len)
        return(1);
    map_list->rows = y;
    map_list->columns = len;

    return(0);
}

int validate_structure(char **map, t_map *map_list)
{
    int y;
    int x;
    int cant;
    int len;
    int l ;

    x = ((y = 0), (len = 0),(l = 0), 0);
    if(validate_len(map, map_list) == 1)
        return(1);
    while(map[len])
        len ++;
    len -= 1;
    while(map[0][x])
        if(map[0][x++] != '1')
            return(1);  
    x = 0;
    while(map[len][x])
        if(map[len][x++] != '1')
            return(1);
    len ++;
    while(len --)
        if(map[y++][0] != '1')
            return(1);
    y = ((x --), 0);
    while(l--)
        if(map[y++][x] != '1')
            return(1);
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
    int     ob;

    map->n_exits = 0;
    map->n_inits = 0;
    map->n_objects = 0;
    map_str = NULL;
    map->program = malloc(sizeof(t_minilib));
    if(create_map_str(fd, map, &map_str) == 1)
        return(NULL);
    map_bi = create_map(map_bi, &map_str);
    if(validate_structure(map_bi, map) == 1)
        return((return_error("invalid map\n", NULL, map_bi)), NULL);
    position_p(map_bi, map);
    map->map_copy = ft_strdup_array_bi(map_bi);
    if(map->map_copy == NULL)
        return((return_error("creation of map_copy fail\n", NULL, map_bi)), NULL);
    map->map_real = map_bi;
    ///por q ob
    ob = map->n_objects;
    validate_path(map, map->P.y, map->P.x, &ob);
    ft_freecharmatrix(map->map_copy);
    if(ob > 0 || map->n_exits == 1)
        return(NULL);
    return (map_bi);
}
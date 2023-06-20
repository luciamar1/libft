/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:48:04 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/06/20 12:23:51 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int validate_path(t_map map)
{
    t_map_list  *path;
    path = malloc(sizeof(t_map_list));


    
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
            map->E = map->E + 1;
        if (*s == 'C')
           map->object = map->object + 1;
        if (*s == 'P')
           map->init = map->init + 1;
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
            map->init = -1;
            break;
        }
        *map_str = ft_strjoin_chetao(map_str, &line_map);
    }
    if(map->E != 1 || map->init != 1 || map->object < 1)
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

char    **check_map(int argc, char **argv, int fd, t_map *map)
{
    char    *map_str;
    char    **map_bi;
    char    *old_line_map;

    map->E = 0;
    map->init = 0;
    map->object = 0;
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
    return (map_bi);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:48:04 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/06/12 21:01:03 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

char **check_file(int argc, char **argv)
{
    int fd;
    char **map;
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
    map = check_map(argc, argv, fd);
    return (map);
}

int	ft_strchr_so_long(char *s, int *E, int *init, int *object)
{
	while (*s)
	{
		if (*s == 'E')
            *E = *E + 1;
        if (*s == 'C')
           *object = *object + 1;
        if (*s == 'P')
           *init = *init + 1;
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


char    **check_map(int argc, char **argv, int fd)
{
    char    *line_map;
    char    *map_str;
    int     E;
    int     init;
    int     object;
    int     counter;
    char    **map;
    char    *old_line_map;

    E = 0;
    init = 0;
    object = 0;
    map_str = NULL;
    while(1)
    {
        counter = 0;
        line_map = get_next_line(fd);
        if(!line_map)
            break;
        if(ft_strchr_so_long(line_map, &E, &init, &object) == 1)
        {
            free(line_map);
            init = -1;
            break;
        }
        
        map_str = ft_strjoin_chetao(&map_str, &line_map);
    }

    if(E != 1 || init != 1 || object < 1)
    {
        return_error("invalid map", &map_str);
        return(NULL);
    }
    map = create_map(map, &map_str);
    if(map == NULL)
        return (NULL);
 
    return(map);
}
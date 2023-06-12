/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:48:04 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/06/12 01:59:34 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	return_error(char *message, char **map)
{
	if (map)
		free(*map);
	//printf("Error\n%s%s%s\n", RED, message, DEFAULT);
    while(*message)
        write(1, message++, 1);
    write(1, "\n", 1);
	exit(0);
}

char **check_file(int argc, char **argv)
{
    int fd;
    if(argc != 2)
    {
        return_error("the number of arguments is wrong =(", NULL);
        return(NULL);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        return_error("the file can't be open =(", NULL);
        return(NULL);
    }
    if(ft_str_rev_n_cmp(argv[1], ".ber", 4) != 0)
    {
        return_error("the file is not .ber =(", NULL);
        return(NULL);
    }
    printf("here?? %s\n", *(check_map(argc, argv, fd)));
    return(check_map(argc, argv, fd));
}

char    **check_map(int argc, char **argv, int fd)
{
    char    *line_map;
    char    *map_str;
    int     exit;
    int     init;
    int     object;
    int     counter;
    char    **map;
    char    *old_line_map;

    exit = 0;
    init = 0;
    //map = NULL;
    object = 0;
    map_str = NULL;
    while(1)
    {
        //sleep(2);

        counter = 0;
        line_map = get_next_line(fd);
        if(!line_map)
            break;
        if(ft_strchr(line_map, 'E'))
            exit++;
        if(ft_strchr(line_map, 'P'))
            init++;
        if(ft_strchr(line_map, 'C'))
            object++;
        map_str = ft_strjoin_chetao(&map_str, &line_map);

    }
    printf("map == %s\n", map_str);

    if(exit != 1 || init != 1 || object < 1)
    {
        return_error("invalid map", &map_str);
        return(NULL);
    }
    else
    {
        map == ft_split(map_str, '\n');
        if(map == NULL)
        {
            return_error("split fail", &map_str);
            return(NULL);
        }  
    }
    return(map);
}
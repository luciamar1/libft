/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:48:04 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/06/11 01:57:08 by lucia-ma         ###   ########.fr       */
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

int check_file(int argc, char **argv)
{
    int fd;
    if(argc != 2)
    {
        return_error("the number of arguments is wrong =(", NULL);
        return(1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        return_error("the file can't be open =(", NULL);
        return(1);
    }
    if(ft_str_rev_n_cmp(argv[1], ".ber", 4) != 0)
    {
        return_error("the file is not .ber =(", NULL);
        return(1);
    }

}
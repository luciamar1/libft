/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:48:04 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/07/21 23:43:43 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void	valgrind(void)
 {
 	system("valgrind -s --leak-check=full ./so_long");

 }*/
int on_destroy(t_minilib *data)
{
	// mlx_destroy_window(data->mlx_pointer, data->window);
	// mlx_destroy_display(data->mlx_pointer);
	// free(data->mlx_pointer);
	exit(0);
	return (0);
}


int on_keypress(int keysym, t_minilib *data)
{
	(void)data;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}

int main(int argc, char **argv)
{

	char	**map_bi;
	t_map	map;
	map_bi = checker(argc, argv, &map);
	if (map_bi == NULL)
		return(1);	
	start_game(&map);
    return(0);
}

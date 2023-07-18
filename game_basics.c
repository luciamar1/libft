/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_basics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:47:49 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/07/18 21:44:36 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int start_game(t_map *map, t_minilib *program)
{
    void    *img;
    int     size;

    size = SIZE;
    program->mlx_pointer = mlx_init();
	if(!program->mlx_pointer)
		return(1);
    program->window = mlx_new_window(program->mlx_pointer, map->columns * SIZE, map->rows * SIZE, "Hellow minilib =)");
    if(!program->window)
	    return(free(program->mlx_pointer), 1);

    img = mlx_xpm_file_to_image(program->mlx_pointer, "./sprites/Pink_Monster_Run_6.xpm", &size, &size);
    printf("guaaaa\n");
    mlx_put_image_to_window(program->mlx_pointer, program->window, img, 0, 0);
    mlx_destroy_image(program->mlx_pointer, img); 
    mlx_loop(program->mlx_pointer);
    mlx_destroy_window(program->mlx_pointer,program->window);

   ////                                                 CREAR UPDATE
   //mlx_loop_hook(program->mlx_ptr, ft_update())
    return(0);
    
}
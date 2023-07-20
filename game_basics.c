/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_basics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:47:49 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/07/20 22:40:25 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void    put_image(t_map *map, t_minilib *program, int x, int y)
// {
//     void    *img;
//     int     size;
    
//     size = SIZE;
//     img = mlx_xpm_file_to_image(program->mlx_pointer, "./sprites/Pink_Monster_Run_6.xpm", &size, &size);
//     mlx_put_image_to_window(program->mlx_pointer, program->window, img, x * 32,  y * 32);
//     mlx_destroy_image(program->mlx_pointer, img); 
    
// }

void    put_image(t_map *map, t_minilib *program, int x, int y)
{
    void    *img;
    int     size;
    
    size = SIZE;
    if(map->map_real[y][x] == 'P')
    {
        img = mlx_xpm_file_to_image(program->mlx_pointer, "./sprites/Pink_Monster_Run_6.xpm", &size, &size);
    }
     if(map->map_real[y][x] == 'E')
    {
        img = mlx_xpm_file_to_image(program->mlx_pointer, "./sprites/Pink_Monster_Run_6.xpm", &size, &size);
    }
    if(map->map_real[y][x] == '1')
    {
        img = mlx_xpm_file_to_image(program->mlx_pointer, "./sprites/Pink_Monster_Run_6.xpm", &size, &size);
    }
    if(map->map_real[y][x] == '0')
    {
        img = mlx_xpm_file_to_image(program->mlx_pointer, "./sprites/Pink_Monster_Run_6.xpm", &size, &size);
    }
    if(map->map_real[y][x] == 'O')
    {
        img = mlx_xpm_file_to_image(program->mlx_pointer, "./sprites/Pink_Monster_Run_6.xpm", &size, &size);
    }
    if(map->map_real[y][x] == 'C')
    {
        img = mlx_xpm_file_to_image(program->mlx_pointer, "./sprites/Pink_Monster_Run_6.xpm", &size, &size);
    }
    printf("        %c\n", map->map_real[y][x] );
    mlx_put_image_to_window(program->mlx_pointer, program->window, img, x * 32,  y * 32);
    mlx_destroy_image(program->mlx_pointer, img); 
    
}

int start_game(t_map *map, t_minilib *program)
{
    int     size;
    
    map->position_to_paint.x = 0;
    map->position_to_paint.y = 0;
    size = SIZE;
    program->mlx_pointer = mlx_init();
	if(!program->mlx_pointer)
		return(1);
    program->window = mlx_new_window(program->mlx_pointer, map->columns * SIZE, map->rows * SIZE, "Hellow minilib =)");
    if(!program->window)
	    return(free(program->mlx_pointer), 1);
    while(map->map_real[map->position_to_paint.y])
    {
        while(map->map_real[map->position_to_paint.y][map->position_to_paint.x])
        {
            printf("%c\n", map->map_real[map->position_to_paint.y][map->position_to_paint.x]);
            //printf("%d      %d\n", map->position_to_paint.y, map->position_to_paint.x);
            put_image(map, program, map->position_to_paint.x, map->position_to_paint.y);
            map->position_to_paint.x++;
        }
        printf("\n");
        map->position_to_paint.x = 0;
        map->position_to_paint.y++;
    }
    mlx_loop(program->mlx_pointer);
    mlx_destroy_window(program->mlx_pointer,program->window);

    ////                                                 CREAR UPDATE
    //mlx_loop_hook(program->mlx_ptr, ft_update())
    return(0);
    
}
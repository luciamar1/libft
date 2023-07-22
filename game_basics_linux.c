/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_basics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:47:49 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/07/22 00:32:29 by lucia-ma         ###   ########.fr       */
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



/// a = 97  s = 115 d == 100 w == 119

void    put_image(t_map *map, t_minilib *program, int x, int y)
{
    void    *img;
    int     size;
    
    size = SIZE;
    if(map->map_real[y][x] == 'P')
    {
        program->P.x = x;
        program->P.y = y;
        img = mlx_xpm_file_to_image(program->mlx_pointer, "./sprites/Pink_Monster_Run_6.xpm", &size, &size);
    }
     if(map->map_real[y][x] == 'E')
    {
        img = mlx_xpm_file_to_image(program->mlx_pointer, "./sprites/puerta1.xpm", &size, &size);
    }
    if(map->map_real[y][x] == '1')
    {
        img = mlx_xpm_file_to_image(program->mlx_pointer, "./sprites/bloque.xpm", &size, &size);
    }
    if(map->map_real[y][x] == '0')
    {
        img = mlx_xpm_file_to_image(program->mlx_pointer, "./sprites/fondo.xpm", &size, &size);
    }
    if(map->map_real[y][x] == 'C')
    {
        img = mlx_xpm_file_to_image(program->mlx_pointer, "./sprites/pineaple.xpm", &size, &size);
    }
    mlx_put_image_to_window(program->mlx_pointer, program->window, img, x * 32,  y * 32);
    mlx_destroy_image(program->mlx_pointer, img); 
    
}

void    print_walk(char *array, int size, t_minilib *program, int *vector)
{
       // printf("putt image  x == %d    y == %d\n", x, y);
    int *img;
    img = mlx_xpm_file_to_image(program->mlx_pointer, array, &size, &size);
    if(vector != NULL)
        mlx_put_image_to_window(program->mlx_pointer, program->window, img, ((program->P.x)+vector[0])* 32,  ((program->P.y)+vector[1]) * 32);
    else
        mlx_put_image_to_window(program->mlx_pointer, program->window, img, (program->P.x)* 32,  (program->P.y) * 32);
    mlx_destroy_image(program->mlx_pointer, img); 
    
}

void    move_al_uranio(int key, t_map *map, t_minilib *program, int *vector)
{
     int *img;
    int size;
    static int counter = 0;
    size = SIZE;
    print_walk("./sprites/Pink_Monster_Run_6.xpm", size, program, vector);
    print_walk("./sprites/fondo.xpm", size, program, NULL);
    ////printf("mover al bebe  x == %d    y == %d\n", program->P.x, program->P.y);
    program->P.x += vector[0];
    program->P.y += vector[1];
    ////printf("mover al bebe  x == %d    y == %d\n", program->P.x, program->P.y);
}

void    cerrar(t_map *map, int win)
{
    if(win == 0)
        write(1, "\n\nYUHUUUUUUU SOY LIBREEEE!!!\n\n      GRACIAS =)\n\n", 49);
    else
        write(1, "ooooyyyyeeee no me cierres =(\n", 30);
    mlx_destroy_window(map->program->mlx_pointer,map->program->window);
    exit(0);
}




/// a = 97  s = 115 d == 100 w == 119

int	key_hook(int key, t_map *map)
{
    //printf("huaaaaaalloooaaaaa\n");
    //printf("key == %d\n", key);
    int vector[2];
    int parx;
    int pary;
    vector[0] = 0;
    vector[1] = 0;
    if(key == 97)
        vector[0] = -1;
    if(key == 100)
        vector[0] = +1;
    if(key == 115)
        vector[1] = +1;
    if(key == 119)
        vector[1] = -1;
    parx = map->program->P.x + vector[0];
    pary = map->program->P.y + vector[1];
    
    if(map->map_real[pary][parx] == 'C')
    {
        map->n_objects --;
        map->map_real[pary][parx] = '0';
    }
    //printf("n_objects  == %d\n", map->n_objects);
    if(key == 65307)
        cerrar(map, 1);
    else if((key == 97 || key == 100 || key == 119 || key == 115) && map->map_real[pary][parx] != '1' && map->map_real[pary][parx] != 'E')
        move_al_uranio(key, map, map->program, vector);
    if(map->map_real[pary][parx] == 'E' && map->n_objects == 0)
        cerrar(map, 0);
	return (0);
}

int start_game(t_map *map)
{
    int     size;

    map->position_to_paint.x = 0;
    map->position_to_paint.y = 0;
    size = SIZE;
    map->program->mlx_pointer = mlx_init();
	if(!map->program->mlx_pointer)
		return(1);
    map->program->window = mlx_new_window(map->program->mlx_pointer, map->columns * SIZE, map->rows * SIZE, "Hellow minilib =)");
    if(!map->program->window)
	    return(free(map->program->mlx_pointer), 1);
    while(map->map_real[map->position_to_paint.y])
    {
        while(map->map_real[map->position_to_paint.y][map->position_to_paint.x])
        {
            put_image(map, map->program, map->position_to_paint.x, map->position_to_paint.y);
            map->position_to_paint.x++;
        }
        map->position_to_paint.x = 0;
        map->position_to_paint.y++;
    }
    mlx_hook(map->program->window, 17, 1L << 17, key_hook, map);
    mlx_key_hook(map->program->window, key_hook, map);
    //ft_print_array_bi(map->map_real);
    mlx_loop(map->program->mlx_pointer);
    return (0);
}

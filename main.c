/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:48:04 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/06/28 17:32:58 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void	valgrind(void)
 {
 	system("valgrind -s --leak-check=full ./so_long");

 }*/
int on_destroy(t_minilib *data)
{
	mlx_destroy_window(data->mlx_pointer, data->window);
	mlx_destroy_display(data->mlx_pointer);
	free(data->mlx_pointer);
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
    t_minilib   program;
	map_bi = check_file(argc, argv, &map);
	if(map_bi == NULL)
		return(1);	
	ft_print_array_bi(map_bi);
	start_game(&map, &program);
	//valgrind();
	//mlx_loop(program.mlx_pointer);
	//mlx_hook(program.mlx_pointer, KeyRelease, KeyReleaseMask, &on_keypress, &program);
	//mlx_hook(program.window, DestroyNotify, StructureNotifyMask, &on_destroy, &program);
	//mlx_loop(program.mlx_pointer);
	
	ft_freecharmatrix(map_bi);
    return(0);
}
/*
mlx_put_image_to_window
int main()
{
	// ----------

	// Struct with all the info that I need to run the program (mlx_sample.h)
	t_minilib program;
	// mlx function that initialize the mlx and returns a pointer to it.
	program.mlx_pointer = mlx_init();
	// Open a window (window.c whitin this project)
	program.window = mlx_new_window(program.mlx_pointer, 1980, 1080, "Hello world!");

	// ----------

	// Create a new image/sprite (image.c)
	program.sprite = mlx_new_sprite(program.mlx_pointer, "block.xpm");
	program.sprite_position.x = 0;
	program.sprite_position.y = 0;
	// mlx function that draws an image into a window at the given position
	mlx_put_image_to_window(program.mlx_pointer, program.window->reference,
		program.sprite.reference, program.sprite_position.x, program.sprite_position.y);

	// ----------

	// hook the input() (hooks.c) function to the the key pressed event
	mlx_key_hook(program.window.reference, *mlx_input, &program);
	// hook a function to the loop (it would be called each frame)
	mlx_loop_hook(program.mlx_pointer, *mlx_update, &program);

	// ----------

	// mlx constant loop that keeps the detects the events
    
	mlx_loop(program.mlx_pointer);
}*/

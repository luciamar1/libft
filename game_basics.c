/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:47:49 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/06/28 16:34:37 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int start_game(t_map *map, t_minilib *program)
{
    program->mlx_pointer = mlx_init();
	if(!program->mlx_pointer)
		return(1);
    program->window = mlx_new_window(program->mlx_pointer, map->columns * SIZE, map->rows * SIZE, "Hellow minilib =)");
    if(!program->window)
	    return(free(program->mlx_pointer), 1);
   // mlx_loop(program->mlx_pointer);
   ////                                                 CREAR UPDATE
   mlx_loop_hook(program->mlx_ptr, ft_update())
    return(0);
    
}
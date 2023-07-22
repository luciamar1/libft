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

 void	fre(void)
 {
 	system("leaks -q push_swap");
 }

void	valgrind(void)
 {
 	system("valgrind -s --leak-check=full ./so_long");

 }
void	leaks(void)
{
	system("leaks -q pipex");
}

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

	int	check;
	t_map	map;
	check = checker(argc, argv, &map);
	if (check == 1)
		return(1);	
	valgrind();
	start_game(&map);

    return(0);
}

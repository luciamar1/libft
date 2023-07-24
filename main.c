/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:48:04 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/07/24 14:49:25 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fre(void)
{
	system("leaks -q so_long");
}

void	valgrind(void)
{
	system("valgrind -s --leak-check=full ./so_long");
}

void	leaks(void)
{
	system("leaks -q pipex");
}

int	on_keypress(int keysym, t_minilib *data)
{
	(void)data;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}

int	main(int argc, char **argv)
{
	int		check;
	t_map	map;

	check = checker(argc, argv, &map);
	if (check == 1)
		return (1);
	fre();
	start_game(&map);
	return (0);
}

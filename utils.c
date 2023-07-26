/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:48:04 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/07/26 18:02:45 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	return_error(char *message, char *map_str, char **map_bi)
{
	if (map_str)
		free(map_str);
	if (map_bi)
		ft_freecharmatrix(map_bi);
	while (*message)
		write (1, message++, 1);
	write(1, "\n", 1);
}

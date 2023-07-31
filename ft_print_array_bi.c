/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array_bi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 02:22:47 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/07/27 16:17:37 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_array_bi(char **array)
{
	int	y;

	y = 0;
	while (array[y])
	{
		printf("array  ==  %s\n", array[y]);
		y ++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeintmatrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:27:37 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/02/27 14:34:51 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freeintmatrix(int **matrix, int sec_dimension)
{
	int	i;

	i = 0;
	while (i < sec_dimension)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

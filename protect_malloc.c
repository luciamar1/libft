/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:13:37 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/07/27 16:21:41 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*protect_malloc(size_t n)
{
	static int	cnt = 0;

	if (cnt == MALLOC_FAIL)
		return (NULL);
	cnt ++;
	return (calloc(n, 1));
}

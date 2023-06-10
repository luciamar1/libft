/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 02:23:47 by lucia-ma          #+#    #+#             */
/*   Updated: 2022/09/18 21:03:25 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char*restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	z;

	if (dstsize == 0)
	{
		if ((src == 0 || dst == 0) && dstsize == 0)
			return (0);
		return (ft_strlen(src));
	}
	z = --dstsize;
	while (src[z - dstsize] && dstsize)
	{
		dst[z - dstsize] = src[z - dstsize];
		dstsize --;
	}
	dst[z - dstsize] = '\0';
	z = ft_strlen(src);
	return (z);
}

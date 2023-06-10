/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 02:22:56 by lucia-ma          #+#    #+#             */
/*   Updated: 2022/09/18 20:57:11 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;

	if (dest == 0 && src == 0)
		return (0);
	d = dest;
	while (n)
	{
		*d = *(char *)src;
		src ++;
		d ++;
		n --;
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 02:22:59 by lucia-ma          #+#    #+#             */
/*   Updated: 2022/09/18 20:57:24 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	char		*d;
	const char	*s;
	size_t		z;

	if (dest == 0 && src == 0)
		return (0);
	z = count;
	s = src;
	d = dest;
	if (src < dest)
		while (count--)
			d[count] = s[count];
	else
	{
		while (count)
		{
			d[z - count] = s[z - count];
			count --;
		}
	}
	return (dest);
}

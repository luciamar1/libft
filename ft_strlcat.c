/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 02:23:44 by lucia-ma          #+#    #+#             */
/*   Updated: 2022/09/21 22:56:47 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char	*d;

	d = dest;
	if (size == 0)
		return (ft_strlen(src));
	if (size <= ft_strlen(dest))
		return (ft_strlen(src) + size);
	if (src == 0)
		return (0);
	else
	{
		while (*d && size--)
			d++;
		while (*src && --size)
			*d ++ = *(char *)src++;
		*d = '\0';
		return (ft_strlen(dest) + ft_strlen(src));
	}
}

// int main(void)
// {
// 	char dest[30]; memset(dest, 0, 30);
//     char * src = (char *)"AAAAAAAAA";
//     dest[0] = 'B';
// 	printf("%d",ft_strlcat(dest, src, 0));
// 	printf("%d",strlcat(dest, src, 0));
// }
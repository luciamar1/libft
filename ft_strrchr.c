/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 02:24:05 by lucia-ma          #+#    #+#             */
/*   Updated: 2022/09/18 20:59:21 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*s;

	s = (char *)str;
	while (*str)
	{
		if (*str == (char)(c & 0xff))
			s = (char *)str;
		str ++;
	}
	if ((char)(c & 0xff) == '\0' && *str == '\0')
		return ((char *)str);
	if (*s == (char)(c & 0xff) || (char)(c & 0xff) == 0)
		return (s);
	return (NULL);
}

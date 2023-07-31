/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 02:24:02 by lucia-ma          #+#    #+#             */
/*   Updated: 2022/09/21 22:59:45 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>

char	*ft_strnstr(const char *s, const char *f, size_t n)
{
	size_t	lf;

	if (!s && !n)
		return (NULL);
	lf = ft_strlen(f);
	if (!lf)
		return ((char *)s);
	while (*s && n != 0)
	{
		if (!ft_strncmp(s, f, lf) && (lf <= n))
			return ((char *)s);
		s++;
		n--;
	}
	return (NULL);
}

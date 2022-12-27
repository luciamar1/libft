/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 02:24:12 by lucia-ma          #+#    #+#             */
/*   Updated: 2022/09/18 20:59:31 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	x;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		d = ft_calloc(1, 1);
		return (d);
	}
	if (len >= ft_strlen(s + start))
		len = ft_strlen(s + start);
	d = malloc(len + 1 * sizeof(char));
	if (d == NULL)
		return (NULL);
	x = len;
	s += start;
	while (len --)
		*d++ = *s++;
	*d = 0;
	return (d - x);
}

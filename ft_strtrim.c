/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 02:24:08 by lucia-ma          #+#    #+#             */
/*   Updated: 2022/09/18 21:03:52 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *to_find)
{
	int	l;

	if (!s || !to_find)
		return (NULL);
	while (*s && ft_strchr(to_find, *s))
		s ++;
	l = ft_strlen(s);
	while (l && ft_strchr(to_find, s[l]))
		l --;
	return (ft_substr(s, 0, l + 1));
}

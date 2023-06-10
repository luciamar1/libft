/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 02:23:30 by lucia-ma          #+#    #+#             */
/*   Updated: 2022/08/12 02:28:31 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char			*s;
	unsigned int	sl;

	sl = ft_strlen(str);
	s = malloc(sl * sizeof(char) + 1);
	if (s == NULL)
		return (NULL);
	while (*str)
	{
		*s = *str;
		s ++;
		str ++;
	}
	*s = '\0';
	return (s - sl);
}

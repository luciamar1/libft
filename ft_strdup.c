/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 02:23:30 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/07/27 16:16:39 by lucia-ma         ###   ########.fr       */
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

char	**ft_strdup_array_bi(char **str)
{
	char	**copy;
	int		counter;

	counter = 0;
	copy = malloc(sizeof(char *) * ft_strlen_array_bi(str));
	while (str[counter])
	{
		copy[counter] = ft_strdup(str[counter]);
		if (copy[counter] == NULL)
		{
			ft_freecharmatrix(copy);
			return (NULL);
		}
		counter ++;
	}
	return (copy);
}

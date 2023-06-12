/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 02:23:40 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/06/12 01:33:40 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		l;

	if (!s1 || !s2)
		return (NULL);
	l = ft_strlen(s1) + ft_strlen(s2);
	s = malloc(l * sizeof(char) + 1);
	if (s == NULL)
		return (NULL);
	while (*s1)
		*s++ = *s1++;
	while (*s2)
		*s++ = *s2++;
	*s = 0;
	return (s - l);
}

char	*ft_strjoin_chetao(char **s1, char **s2)
{
	char	*s;
	int		l;
	int		counter;

	counter = 0;
	if (!s2)
		return (NULL);
	if(*s1)
		l = ft_strlen(*s1) + ft_strlen(*s2);
	else
		l =ft_strlen(*s2);
	s = malloc(l * sizeof(char) + 1);
	if (s == NULL)
		return (NULL);
	while (*s1 && s1[0][counter])
		*s++ = s1[0][counter++];
	counter = 0;
	while (s2[0][counter])
		*s++ = s2[0][counter++];
	*s = 0;
	free(*s2);
	if(s1)
		free(*s1);
	return (s - l);
}

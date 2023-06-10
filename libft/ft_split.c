/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 02:23:17 by lucia-ma          #+#    #+#             */
/*   Updated: 2022/09/18 20:58:03 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*mallocseg(char *m, char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	m = (char *)malloc((i + 1) * sizeof(char));
	if (!m)
		return (NULL);
	m[i] = 0;
	return (m);
}

char	*pon(const char **s, char c, char *m)
{
	int	n;

	n = 0;
	if (m == 0)
		return (m);
	while (**s && **s != c)
	{
		m[n ++] = **s;
		(*s)++;
	}
	return (m);
}

int	pridimensioncount(char const *s, char c)
{
	int	p;

	p = 1;
	if (*s == c)
		p--;
	if (!*s)
		return (0);
	while (*s)
	{
		if ((*s == c && *(s + 1) != c) && *(s + 1) != '\0')
			p ++;
		s++;
	}
	return (p);
}

void	m_free(char **m, int i, int p)
{
	while (i - p++)
		free(*(--m));
	free(m);
}

char	**ft_split(char const *s, char c)
{
	char	**m;
	int		p;
	int		i;

	if (!s)
		return (NULL);
	else
		p = pridimensioncount(s, c);
	m = malloc((p + 1) * sizeof(char *));
	if (!m)
		return (NULL);
	i = p;
	m[p] = NULL;
	while (p--)
	{
		while (*s && *s == c)
			s++;
		*m = pon(&s, c, mallocseg(*m, (char *)s, c));
		if (!*m)
			m_free(m, i, p);
		m++;
	}
	return (m - i);
}

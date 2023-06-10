/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 02:21:23 by lucia-ma          #+#    #+#             */
/*   Updated: 2022/09/18 21:02:42 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Parámetros n: el entero a convertir.
// Valor devuelto: La string que represente el número.
// NULL si falla la reserva de memoria.
// Funciones autorizadas
// malloc
// Descripción Utilizando malloc(3), genera una string que
// represente el valor entero recibido como argumento.
// Los números negativos tienen que gestionarse.

void	putnb(long int nb, char **s)
{
	if (nb < 0)
	{
		**s = '-';
		(*s)++;
		nb *= -1;
	}
	if (nb > 9)
	{
		putnb(nb / 10, s);
		(*s)++;
	}
	**s = '0' + nb % 10;
}

int	lenint(long int n)
{
	int	l;

	l = 1;
	if (n < 0)
	{
		l++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		l ++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	long int	nb;
	int			l;
	char		*s;

	nb = n;
	l = lenint(nb);
	s = (char *)malloc((l + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[l] = 0;
	putnb(nb, &s);
	s -= l - 1;
	return (s);
}

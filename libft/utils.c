/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:19:31 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/07/24 14:42:03 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_putchar(char a)
{
	write(1, &a, 1);
	return (1);
}

int	ft_putnbr(int nb)
{
	long int	n;
	int			counter;

	counter = 0;
	n = nb;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
		counter = ft_putnbr((n / 10));
	ft_putchar('0' + n % 10);
	counter ++;
	if (nb < 0)
		return (counter + 1);
	return (counter);
}

int	ft_putstr(const char *s)
{
	int	l;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	l = 0;
	while (*s)
	{
		write(1, s++, 1);
		l++;
	}
	return (l);
}

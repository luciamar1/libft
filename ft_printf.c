/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:19:24 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/07/24 14:41:14 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>

int	ft_whall_happen(va_list *args, char happen)
{
	if (happen == 'd' || happen == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (happen == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (happen == 's')
		return (ft_putstr(va_arg(*args, const char *)));
	else if (happen == 'p')
		return (ft_putptr_base((unsigned long long)
				(va_arg(*args, void *)), "0123456789abcdef", 'p') + 2);
	else if (happen == 'u')
		return (ft_putptr_base(va_arg(*args, unsigned int), "0123456789", 0));
	else if (happen == 'x')
		return (ft_putptr_base((unsigned int)
				va_arg(*args, unsigned long), "0123456789abcdef", 0));
	else if (happen == 'X')
		return (ft_putptr_base ((unsigned int)
				va_arg(*args, unsigned long), "0123456789ABCDEF", 0));
	else if (happen == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		countch;

	countch = 0;
	va_start(args, s);
	if (!s)
		write(1, "ERROR", 6);
	while (*s)
	{
		if (*s == '%')
		{
			countch += ft_whall_happen(&args, s[1]);
			s++;
		}
		else
		{
			write(1, s, 1);
			countch ++;
		}
		if (*s)
			s++;
	}
	return (countch);
}

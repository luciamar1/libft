/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 02:23:11 by lucia-ma          #+#    #+#             */
/*   Updated: 2022/08/12 02:23:11 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_char(char a, int fd)
{
	write(fd, &a, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	long int	n;

	n = nb;
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr_fd((n / 10), fd);
	put_char('0' + n % 10, fd);
}

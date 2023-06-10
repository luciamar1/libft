/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 02:22:13 by lucia-ma          #+#    #+#             */
/*   Updated: 2022/08/12 02:22:14 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *lista)
{
	if (!lista || !lst)
		return ((void) NULL);
	if (lst != NULL)
		lista -> next = *lst;
	*lst = lista;
}

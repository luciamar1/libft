/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 02:22:16 by lucia-ma          #+#    #+#             */
/*   Updated: 2022/08/12 02:22:16 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lista;
	t_list	*aux;

	if (!lst || !*lst || !del)
		return ;
	lista = *lst;
	while (lista)
	{
		aux = lista -> next;
		ft_lstdelone(lista, del);
		lista = aux;
	}
	*lst = NULL;
}

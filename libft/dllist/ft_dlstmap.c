/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 13:16:03 by dbotova           #+#    #+#             */
/*   Updated: 2016/10/02 13:16:04 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dllist.h"

t_dlist	*ft_dlstmap(t_dlist *lst, t_list *(*f)(t_dlist *elem))
{
	t_dlist *result;
	t_dlist *tmp;
	t_dlist *prev;

	result = NULL;
	if (lst)
	{
		result = f(lst);
		prev = result;
		lst = lst->next;
		while (lst)
		{
			tmp = f(lst);
			prev->next = tmp;
			prev = tmp;
			lst = lst->next;
		}
		prev->next = NULL;
	}
	return (result);
}

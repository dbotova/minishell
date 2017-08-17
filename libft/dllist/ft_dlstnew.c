/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 11:45:19 by dbotova           #+#    #+#             */
/*   Updated: 2016/10/02 11:45:20 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "llist.h"

t_dlist	*ft_dlstnew(void const *content, size_t content_size)
{
	t_dlist *list;

	list = (t_dlist*)malloc(sizeof(t_dlist));
	if (list)
	{
		if (content)
		{
			if (!(list->content = (void *)malloc(sizeof(void) * content_size)))
				return (NULL);
			ft_memset(list->content, 0, content_size + 1);
			ft_memcpy(list->content, content, content_size);
			list->content_size = content_size;
			list->next = NULL;
		}
		else
		{
			list->content = NULL;
			list->content_size = 0;
		}
	}
	return (list);
}

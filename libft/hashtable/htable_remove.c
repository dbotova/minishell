/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htable_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 10:31:45 by dbotova           #+#    #+#             */
/*   Updated: 2017/08/17 10:31:46 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"


void			htable_remove(t_hashtable *table, void *object, size_t size)
{
	unsigned int	hash;
	t_dlist			*cur;

	hash = ft_hash(object, ft_strlen(object) + 1);
	cur = NULL;
	if (hash < table->size)
	{	
		cur = table->data[hash];
		if (!cur)
			return ;
		while (cur && ft_memcmp(cur->content, object, size) != 0)
			cur = cur->next;
		if (cur)
			ft_dlstdelone(&cur, ft_ddel);
	}	
}

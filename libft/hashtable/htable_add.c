/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htable_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 10:31:36 by dbotova           #+#    #+#             */
/*   Updated: 2017/08/17 10:31:38 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

void			htable_add(t_hashtable *table, void *object, unsigned int size,
				void (*hash)(void *, size_t))
{
	unsigned int	hash;
	t_dlist			*new;

	new = ft_dlstnew(object, size);
	hash = hash(object, ft_strlen(object));
	if (hash > table->size)
		ft_dlstadd(&table->data[hash], new);
}

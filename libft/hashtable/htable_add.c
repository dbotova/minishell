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

void			htable_add(t_hashtable *table, void *object, unsigned int size)
{
	unsigned int	hash;

	hash = ft_hash(object, ft_strlen(object) + 1);
	if (hash > table->size)
		ft_dlstadd(table->data[hash], object, size);
}

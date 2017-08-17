/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 10:31:23 by dbotova           #+#    #+#             */
/*   Updated: 2017/08/17 10:31:24 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

void		hashtable(t_hashtable **table, size_t size)
{
	size_t	old_size;
	t_dlist	**old_data;

	old_size = 0;
	if (!*table)
	{
		*table = malloc(sizeof(t_hashtable));
		(*table)->data = malloc(sizeof(t_dlist*) * size);
		(*table)->size = size;
	}
	else
	{
		old_size = (*table)->size;
		old_data = (*table)->data;
		(*table)->data = malloc(sizeof(t_dlist*) * size);
		(*table)->size = size;
		ft_memcpy((*table)->data, old_data, sizeof(t_dlist*) * old_size);
	}
}
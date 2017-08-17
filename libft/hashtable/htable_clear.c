/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htable_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 10:32:38 by dbotova           #+#    #+#             */
/*   Updated: 2017/08/17 10:32:39 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

void				htable_clear(t_hashtable *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->size)
	{
		ft_dlstdel(&table->data[hash], ft_del);
		i++;
	}
}
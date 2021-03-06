/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htable_has_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 10:31:56 by dbotova           #+#    #+#             */
/*   Updated: 2017/08/17 10:32:02 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

int		htable_has_key(t_hashtable *table, unsigned int key) //implement
{
	if (table && key > 1)
		return (1);
	return (0);
}

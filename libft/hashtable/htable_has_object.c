/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htable_has_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 10:32:21 by dbotova           #+#    #+#             */
/*   Updated: 2017/08/17 10:32:22 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

int				htable_has_object(t_hashtable *table, void *object) //implement
{
	if (table && object)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:32:34 by dbotova           #+#    #+#             */
/*   Updated: 2017/05/21 17:32:35 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_wrap.h"

void	add_element(t_array_wrap **array, char *new_item)
{
	if ((*array)->used == (*array)->size)
		*array = realloc_array(*array, (*array)->size + SIZE_BLOCK);
	ft_strcpy((*array)->data[(*array)->used], new_item);
	(*array)->used++;
}

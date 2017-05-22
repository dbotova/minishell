/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:32:13 by dbotova           #+#    #+#             */
/*   Updated: 2017/05/21 17:32:14 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_wrap.h"

t_array_wrap		*realloc_array(t_array_wrap *old_array, size_t new_size)
{
	t_array_wrap	*new_array;
	size_t			i;

	i = 0;
	init_array(&new_array, new_size);
	while(i < old_array->size)
	{
		ft_strcpy(new_array->data[i], old_array->data[i]);
		i++;
	}
	new_array->used = old_array->size;
	return (new_array);
}

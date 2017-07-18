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

t_array_wrap		*realloc_array(t_array_wrap *array, size_t new_size)
{
	char			**old_data;
	size_t			i;
	size_t			old_size;

	i = 0;
	old_size = array->size;
	old_data = array->data;
	array->data = (char**)malloc(sizeof(char*) * new_size);
	array->size = new_size;
	while (i < new_size)
		array->data[i++] = NULL;
	ft_memcpy(array->data, old_data, sizeof(char*) * old_size);
	SMART_FREE(old_data);
	return (array);
}

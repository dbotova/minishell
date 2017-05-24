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
	char			**old_data = array->data;

	array->data = (char**)malloc(sizeof(char*) * new_size);
	ft_memset(array->data, 0, sizeof(char) * new_size);
	ft_memcpy(array->data, old_data, sizeof(char*) * array->size);

	SMART_FREE(old_data);
	return (array);
}

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
	char **old_data = old_array->data;

	old_array->data = (char**)malloc(sizeof(char*) * new_size);
	ft_memset(old_array->data, 0, sizeof(char) * new_size);
	ft_memcpy(old_array->data, old_data, sizeof(char*) * old_array->size);

	SMART_FREE(old_data);
	return (old_array);
}

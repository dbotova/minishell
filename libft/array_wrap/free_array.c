/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:31:58 by dbotova           #+#    #+#             */
/*   Updated: 2017/05/21 17:31:59 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_wrap.h"

void				free_array(t_array_wrap *array)
{
	size_t			i;

	i = 0;
	while (i < array->size)
	{
		if (array->data[i])
			SMART_FREE(array->data[i]);
		i++;
	}
	SMART_FREE(array->data);
	SMART_FREE(array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:36:06 by dbotova           #+#    #+#             */
/*   Updated: 2017/05/21 17:36:07 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_wrap.h"

void		delete_element(t_array_wrap *array, char *element)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(element);
	i = find_element(array, element, len, 0);
	if (i)
		SMART_FREE(array->data[i]);
}
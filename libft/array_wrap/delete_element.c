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

int		delete_element(t_array_wrap *array, char *element)
{
	ssize_t	i;
	size_t	len;

	len = ft_strlen(element);
	i = find_element(array, element, len, '=');
	if (i >= 0)
		SMART_FREE(array->data[i]);
		return (0);
	return (-1);
}
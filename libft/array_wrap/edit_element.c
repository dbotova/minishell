/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editwq_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:32:59 by dbotova           #+#    #+#             */
/*   Updated: 2017/05/21 17:33:00 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_wrap.h"

void				edit_element(t_array_wrap *array, char *item, char *value, char symb)
{
	size_t			i;
	size_t			len;

	len = ft_strlen(item);
	i = find_element(array, item, len, symb);
	if (i)
	{
		ft_memset(array->data[i] + (len + 1), 0, ft_strlen(array->data[i]) - (len + 1));
		ft_strcpy(array->data[i] + (len + 1), value);
	}
}

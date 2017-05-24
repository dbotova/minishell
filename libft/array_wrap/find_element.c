/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:32:48 by dbotova           #+#    #+#             */
/*   Updated: 2017/05/21 17:32:49 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_wrap.h"

size_t				find_element(t_array_wrap *array, char *item, size_t len, char symb)
{
	unsigned int	key;
	size_t			i;

	key = hash(item, len);
	i = 0;
	while (i < array->used)
	{
		if (hash(array->data[i], len) == key)
			if (ft_strncmp(array->data[i], item, len) == 0 &&
				array->data[i][len] == symb)
				return (i);
		i++;
	}
	return (-1);
}

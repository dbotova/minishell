/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:36:21 by dbotova           #+#    #+#             */
/*   Updated: 2017/05/21 17:36:22 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_wrap.h"

void		print_elements(t_array_wrap *array)
{
	size_t	i;

	i = 0;
	while (array && i < array->used)
	{
		if (array->data[i][0] != 0)
			ft_printf(array->data[i]);
		i++;
	}
}

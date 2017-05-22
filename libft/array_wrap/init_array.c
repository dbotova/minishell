/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_wrap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 16:11:02 by dbotova           #+#    #+#             */
/*   Updated: 2017/05/21 16:11:04 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_wrap.h"

void				init_array(t_array_wrap **array, size_t size)
{
	size_t			i;

	i = 0;
	if (!*array)
		*array = malloc(sizeof(t_array_wrap));
	(*array)->data = (char**)malloc(sizeof(char*) * size);
	(*array)->size = size;
	(*array)->used = 0;
	while(i < size)
	{
		(*array)->data[i] = (char*)malloc(sizeof(char) * PATH_MAX);
		ft_memset((*array)->data[i++], 0, sizeof(char) * PATH_MAX);
	}
}

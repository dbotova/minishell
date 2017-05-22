/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:43:50 by dbotova           #+#    #+#             */
/*   Updated: 2017/05/21 17:43:51 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_wrap.h"

void		copy_array(t_array_wrap *array, char **elements)
{
	size_t	i;

	i = 0;
	while (elements[i])
		add_element(array, elements[i++]);
}

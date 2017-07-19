/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dz <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 20:43:00 by dz                #+#    #+#             */
/*   Updated: 2017/07/18 20:43:02 by dz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_wrap.h"

void	str_to_array(t_array_wrap **array, char *str, char c)
{
	char	*str_to_parse;
	char	*tmp;
	char	*match;
	size_t	len;

	if (!str)
		return ;
	str_to_parse = ft_strdup(str);
	tmp = str_to_parse;
	match = NULL;
	len = 0;
	if (!*array)
		init_array(array, SIZE_BLOCK);
	while ((match = ft_strchr(tmp, c)))
	{
		len = ft_strlen(match) - 1; /* minus 1 for found symbol */
		match[0] = 0; /* delete found symbol */
		add_element(*array, tmp);
		tmp = match + 1;
	}
	if (tmp && !match)
		add_element(*array, tmp);
	SMART_FREE(str_to_parse);
}

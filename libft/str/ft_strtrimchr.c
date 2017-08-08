/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 16:35:00 by dbotova           #+#    #+#             */
/*   Updated: 2017/07/11 16:35:04 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

void		ft_strtrimchr(char *str, char c)
{
	char	*match;
	size_t	len;

	match = NULL;
	len = 0;
	while ((match = ft_strchr(str, c)))
	{
		len = ft_strlen(match) - 1; /* minus 1 for found symbol */
		match[0] = 0; /* delete found symbol */
		ft_strcat(match, match + 1);
		str += match - str;
	}
}
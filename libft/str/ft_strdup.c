/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 16:43:50 by dbotova           #+#    #+#             */
/*   Updated: 2016/09/26 16:43:52 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strdup(const char *string)
{
	int		len;
	char	*result;

	len = 0;
	if (!string)
		return (NULL);
	len = (int)ft_strlen(string);
	result = (char *)malloc(sizeof(char) * (len + 1));
	ft_bzero(result, len + 1);
	if (result)
		result = ft_strcpy(result, string);
	return (result);
}

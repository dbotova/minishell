/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dz <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 13:14:03 by dz                #+#    #+#             */
/*   Updated: 2017/05/25 13:14:06 by dz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_setenv(char *name, char *value, int overwrite)
{
	int	exsist;
	char *item;

	item = NULL;
	exsist = find_element(g_envars, name, ft_strlen(name), '=');
	if (exsist >=0 && overwrite != 0)
		edit_element(g_envars, name, value, '=');
	else
	{
		item = (char*)malloc(sizeof(char) *
			(ft_strlen(name) + ft_strlen(value) + 2));
		ft_memset(item, 0, sizeof(item));
		ft_memcpy(item, name, ft_strlen(name));
		ft_memcpy(item + ft_strlen(name), "=", 1);
		ft_memcpy(item + ft_strlen(name) + 1, value, ft_strlen(value));
		add_element(g_envars, item);
		SMART_FREE(item);
	}
	return (0);
}

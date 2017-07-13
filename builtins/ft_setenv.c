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

static int	ft_export(char *var)
{
	char	*name;
	char	*val;
	size_t	val_len;

	val_len = 0;
	name = NULL;
	val = NULL;
	if (!var)
		print_elements(g_envars);
	else
	{
		name = var;
		val = ft_strstr(var, "=") + 1; //check for format
		val_len = ft_strlen(val);
		name[val - var - 1] = 0;
		if (val[0] == '"' && val[val_len - 1] == '"') //check ending qoute 
		{
			val[val_len - 1] = 0;
			val++;
		}
		ft_setenv(name, val, 1);
	}
	return (0);
}

int	ft_setenv_check(char **args)
{
	return (ft_export(args[1]));
}

int		ft_setenv(char *name, char *value, int overwrite) //don't change OLDPWD if path is a current dir
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

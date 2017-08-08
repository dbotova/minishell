/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dz <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 22:16:33 by dz                #+#    #+#             */
/*   Updated: 2017/07/18 22:16:35 by dz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char *remove_relative_path(char *path, char **resolved_path, char *name)
{
	char *absolute_path;

	absolute_path = NULL;
	if (!(absolute_path = ft_getenv(name)))
		return (NULL);
	if (!path)
		ft_strcpy(*resolved_path, absolute_path);
	else
	{
		ft_strcpy(*resolved_path, absolute_path);
		ft_strcat(*resolved_path, path);
	}
	return (*resolved_path);
}

static	char *pre_remove(const char *path, char *resolved_path)
{
	char	*rpath;

	rpath = NULL;
	rpath = ft_strdup(path);
	if (!resolved_path)
		return (NULL);
	if (!rpath && !remove_relative_path(rpath, &resolved_path, "HOME"))
		return (NULL);
	if (rpath && *rpath == '~' && !remove_relative_path(rpath + 1, &resolved_path, "HOME"))
		return (NULL);
	if (rpath && ft_strncmp(rpath, "./", 2) == 0 && !remove_relative_path(rpath + 1, &resolved_path, "PWD"))
		return (NULL);
	if (rpath && ft_strncmp(rpath, "..", 2) == 0 && !remove_relative_path(rpath, &resolved_path, "PWD"))
		return (NULL);
	if (*resolved_path == 0)
		ft_strcpy(resolved_path, path);
	SMART_FREE(rpath);
	return (resolved_path);
}

char	*ft_realpath(const char *path, char *resolved_path)
{
	char	*level_up;
	char	*tmp;

	level_up = NULL;
	tmp = NULL;
	if (!pre_remove(path, resolved_path))
		return (NULL);
	while ((level_up = ft_strstr(resolved_path, "..")))
	{
		tmp = level_up - 1;
		if (*tmp == '/' && tmp != resolved_path)
			*tmp-- = 0;
		while (*tmp != '/' && tmp != resolved_path)
			*tmp-- = 0;
		while (*level_up && *level_up != '/')
			*level_up++ = 0;
		ft_strcat(tmp, ++level_up);
	}
	return (resolved_path);
}


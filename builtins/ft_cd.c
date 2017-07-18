/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dz <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 21:04:11 by dz                #+#    #+#             */
/*   Updated: 2017/05/30 21:04:12 by dz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*get_val(char *item)
{
	char	*val;
	ssize_t	i;

	i = find_element(g_envars, item, ft_strlen(item), '=');
	if (i >= 0)
		val = ft_strstr(g_envars->data[i], "=") + 1;
	return (val);
}

static char *get_full_path(char *path, char *home)
{
	return (ft_strjoin(home, path + 1));
}

void			ft_cd(char **args) //check permisions 
{
	char		*old_pwd;
	char		*buf;
	char		*home;

	buf = (char*)malloc(sizeof(char) * PATH_MAX);
	old_pwd = NULL;
	home = NULL;

	if (!(old_pwd = get_val("PWD")) || !(home = get_val("HOME")))
	{
		ft_printf("no OLDPWD or HOME\n"); //ser errno
		return ;
	}
	if (args[1] && args[1][0] == '~')
		args[1] = get_full_path(args[1], home);
	if (chdir(args[1] ? args[1] : home) < 0)
	{
		//ft_putstr_fd("No such file or directory\n", 2);
		ft_printf("Can't find path: %s or %s\n", args[1], home); //set errno
		return ;
	}
	if (!getcwd(buf, PATH_MAX))
	{
		//set error
		ft_printf("Problem with getcwd\n");
		return ;
	}
	ft_setenv("OLDPWD", old_pwd, 1);
	ft_setenv("PWD", buf, 1);
	SMART_FREE(buf);
}
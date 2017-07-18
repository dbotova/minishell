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

#include "../minishell.h"

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
	if (!(old_pwd = ft_getenv("PWD")) || !(home = ft_getenv("HOME")))
	{
		ft_printf("no OLDPWD or HOME\n"); //ser errno
		return ;
	}
	if (args[1] && args[1][0] == '~')
		args[1] = get_full_path(args[1], home);
	if (args[1] && ft_strcmp(old_pwd, args[1]) == 0)
		return ;
	if (args[1] && check_permission(args[1], R_OK) != 0)
	{
		ft_putstr_fd("Permission denied\n", 2);
		return ;
	}
	if (chdir(args[1] ? args[1] : home) < 0)
	{
		ft_putstr_fd("No such file or directory\n", 2);
		return ;
	}
	if (!getcwd(buf, PATH_MAX))
		return ;
	ft_setenv("OLDPWD", old_pwd, 1);
	ft_setenv("PWD", buf, 1);
	SMART_FREE(buf);
}
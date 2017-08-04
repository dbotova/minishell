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

void			ft_cd(char **args) // cd -
{
	char		*old_pwd;
	char buf[PATH_MAX];
	char resolved_path[PATH_MAX];

	old_pwd = NULL;
	ft_bzero(resolved_path, PATH_MAX);
	if (!(old_pwd = ft_getenv("PWD")))
	{
		ft_printf("no OLDPWD");
		return ;
	}
	if (!ft_realpath(args[1], resolved_path))
	{
		ft_putstr_fd("Path resolving error\n", 2);
		return ;
	}
	if (ft_strcmp(old_pwd, resolved_path) == 0)
		return ;
	if (ft_check_permission(resolved_path, R_OK) != 0)
	{
		ft_putstr_fd("Permission denied\n", 2);
		return ;
	}
	if (chdir(resolved_path) < 0)
	{
		ft_putstr_fd("No such file or directory\n", 2);
		return ;
	}
	if (!getcwd(buf, PATH_MAX))
		return ;
	ft_setenv("OLDPWD", old_pwd, 1);
	ft_setenv("PWD", buf, 1);
}
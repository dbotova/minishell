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

static	char			*get_pwd(char *path, char *resolved_path)
{
	if (!ft_realpath(path, resolved_path))
	{
		ft_putstr_fd("Path resolving error\n", 2);
		return (NULL);
	}
	if (ft_check_permission(resolved_path, R_OK) != 0)
	{
		ft_putstr_fd("Permission denied\n", 2);
		return (NULL);
	}
	return (resolved_path);
}

static void	undo(char *resolved_path, char *cur_pwd)
{
	t_list *old_pwd;
	char				buf[PATH_MAX];

	old_pwd = NULL;
	old_pwd = ft_pop(&g_cd_history);
	if (!old_pwd)
	{
		ft_putstr_fd(NAME, 2);
		ft_putstr_fd(": OLDPWD is not set\n", 2);
		return ;
	}
	else
		ft_memcpy(resolved_path, old_pwd->content, old_pwd->content_size);
	chdir(resolved_path);
	getcwd(buf, PATH_MAX);
	ft_setenv("OLDPWD", cur_pwd, 1);
	ft_setenv("PWD", buf, 1);
	ft_lstdelone(&old_pwd, ft_del);
}

void					ft_cd(char **args)
{
	char				*cur_pwd;
	char				buf[PATH_MAX];
	char				resolved_path[PATH_MAX];

	cur_pwd = NULL;
	ft_bzero(resolved_path, PATH_MAX);
	if (!(cur_pwd = ft_getenv("PWD")))
	{
		ft_printf("PWD is not set\n");
		return ;
	}
	if (args[1] && ft_strcmp(args[1], "-") == 0)
	{
		undo(resolved_path, cur_pwd);
		return ;
	}
	if (!get_pwd(args[1], resolved_path))
		return ;
	if (ft_strcmp(cur_pwd, resolved_path) == 0)
		return ;
	if (chdir(resolved_path) < 0)
	{
		ft_putstr_fd("No such file or directory\n", 2);
		return ;
	}
	if (!getcwd(buf, PATH_MAX))
		return ;
	ft_setenv("OLDPWD", cur_pwd, 1);
	ft_push(&g_cd_history, cur_pwd, ft_strlen(cur_pwd));
	ft_setenv("PWD", buf, 1);
}
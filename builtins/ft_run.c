/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:36:25 by dbotova           #+#    #+#             */
/*   Updated: 2017/07/11 18:36:26 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		check_status(int status)
{
	int			result;

	result = 10;
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGBUS)
			result = 1;
		if (WTERMSIG(status) == SIGSEGV)
			result = 2;
	}
	else
		result = WEXITSTATUS(status);
	return (result);
}

void	ft_run(char *path)
{
	pid_t	pid;
	pid_t	wpid;
	int		result;
	int 	status;
	char	*binary;

	binary = ft_strdup(path);
	binary[ft_strstr(binary, " ") - binary] = 0;
	pid = 0;
	wpid = 0;
	result = 0;
	status = 0;
	if ((pid = fork()) < 0)
		exit(1);
	if (pid == 0)
		execve(binary, path ? ft_strstr(path, " ") + 1 : path, g_envars->data);
	while ((wpid = wait(&status)) > 0)
	{
		if (pid == wpid)
			break ;
		result = check_status(status);
	}
	SMART_FREE(binary);
}

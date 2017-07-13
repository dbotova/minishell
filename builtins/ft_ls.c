/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dz <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 13:42:32 by dz                #+#    #+#             */
/*   Updated: 2017/07/12 13:42:34 by dz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_ls(char **args)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;

	pid = 0;
	wpid = 0;
	status = 0;
	if ((pid = fork()) < 0)
		exit(1);
	else if (pid == 0)
	{
		if (execve("/bin/ft_ls", args, g_envars->data) == -1)
			return ; //set errno
	}
	else // replace do...while
	{
	    do
	    {
	      wpid = waitpid(pid, &status, WUNTRACED);
	    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

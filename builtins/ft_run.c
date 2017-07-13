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

int	ft_run(char **args)
{
	pid_t	pid;
	pid_t	wpid;
	int 	status;

	pid = 0;
	wpid = 0;
	status = 0;
	if ((pid = fork()) < 0)
		exit(1);
	else if (pid == 0)
	{
		if (execve(args[0], args, g_envars->data) == -1)
			return (-1);
	}
	else // replace do...while
	{
	    do
	    {
	      wpid = waitpid(pid, &status, WUNTRACED);
	    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (0);
}

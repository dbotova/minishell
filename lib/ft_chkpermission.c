/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chkpermissio.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 11:01:03 by dbotova           #+#    #+#             */
/*   Updated: 2017/07/18 11:01:05 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_check_permission(char *path, int mode)
{
	if (!access(path, mode))
		return (0);
	return (-1);
}
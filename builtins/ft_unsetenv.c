/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dz <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 13:14:11 by dz                #+#    #+#             */
/*   Updated: 2017/05/25 13:14:13 by dz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_unsetenv_check(char **args)
{
	return (ft_unsetenv(args[1]));
}

int		ft_unsetenv(char *name)
{
	return (delete_element(g_envars, name));
}

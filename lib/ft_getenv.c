/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 10:53:53 by dbotova           #+#    #+#             */
/*   Updated: 2017/07/18 10:53:54 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char		*ft_getenv(char *item)
{
	char	*val;
	ssize_t	i;

	val = NULL;
	i = find_element(g_envars, item, ft_strlen(item), '=');
	if (i >= 0)
		val = ft_strstr(g_envars->data[i], "=") + 1;
	return (val);
}

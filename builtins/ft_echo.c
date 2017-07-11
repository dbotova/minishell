/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dz <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 21:04:19 by dz                #+#    #+#             */
/*   Updated: 2017/05/30 21:04:22 by dz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int 	ft_quote_match(char *path)
{
	int 	count;
	char	*match;

	match = NULL;
	count = 0;
	while ((match = ft_strchr(path, '"')))
	{
		path = match + 1;
		count++;
	}
	if (count % 2 == 0)
		return (0);
	return (1);
}

static void	ft_dquote(t_array_wrap *lines)
{
	char *next;
	int  qoute_end;

	next = NULL;
	qoute_end = 0;
	while (qoute_end == 0)
	{
		ft_printf(DQUOTE);
		get_next_line(0, &next);
		qoute_end = ft_quote_match(next);
		add_element(lines, next);
		SMART_FREE(next);
	}
}

int	ft_echo(char *path)
{
	t_array_wrap *lines;
	size_t		i;

	i = 0;
	lines = (t_array_wrap*)malloc(sizeof(t_array_wrap));
	init_array(&lines, SIZE_BLOCK);
	add_element(lines, path);
	if (ft_quote_match(path))
		ft_dquote(lines);
	while (i < lines->used)
	{
		ft_strtrimchr(lines->data[i], '"');
		ft_printf("%s\n", lines->data[i++]);
	}
	free_array(lines);
	return (0);
}

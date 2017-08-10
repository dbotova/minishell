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

#include "../minishell.h"

static int	echo_read(char **args, int i, t_queue *text)
{
	int qoutes;

	qoutes = 0;
	while(args[i])
	{
		if (ft_strchr(args[i], '"'))
		{
			qoutes++;
			ft_strtrimchr(args[i], '"');
		}
		ft_enqueue(text, args[i], ft_strlen(args[i]));
		i++;
	}
	ft_enqueue(text, "\n", 1);
	return (qoutes);
}

static void	print_text(t_queue *text)
{
	t_list *cur;
	char	env[PATH_MAX];

	cur = NULL;
	bzero(env, PATH_MAX);
	while (!ft_qempty(text))
	{
		cur = ft_dequeue(text);
		if (ft_strncmp(cur->content, "$", 1) == 0)
			/*skip '$' and take variable name */
			ft_strcpy(env, ft_getenv(cur->content + 1));
		else
			ft_strcpy(env, cur->content);
		ft_printf("%s", env);
		if (!ft_qempty(text) && ft_strcmp(env, "\n") != 0)
			ft_putchar(' ');
		ft_lstdelone(&cur, ft_del);
	}
}

int	ft_echo(char **args)
{
	t_queue	*text;
	int		qoutes;
	char	*line;

	text = init_queue();
	qoutes = 0;
	line = NULL;
	qoutes += echo_read(args, 1, text);
	while (qoutes % 2 != 0)
	{
		get_next_line(0, &line);
		qoutes += echo_read(ft_strsplit(line, ' '), 0, text);
		SMART_FREE(line);
	}
	print_text(text);
	return (0);
}

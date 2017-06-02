#ifndef MINISHELL_H
# define MINISHELL_H
# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>
# define MAGIC_NUMBER 42

t_array_wrap *g_envars;

int ft_setenv(char *name, char *value, int overwrite);
int ft_unsetenv(char *name);
void	ft_cd(char *path);
int	ft_echo(char *line);

#endif
#ifndef MINISHELL_H
# define MINISHELL_H
# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>
# include <signal.h>
# define MAGIC_NUMBER 42
# define PROMPT ">> "
# define DQUOTE "<dquote> "

extern t_array_wrap *g_envars;

int		ft_setenv(char *name, char *value, int overwrite);
int		ft_unsetenv(char *name);
void	ft_cd(char *path);
int		ft_echo(char *line);
int		ft_export(char *var);
void	ft_exit(void);
void	ft_run(char *path);

#endif
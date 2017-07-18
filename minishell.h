#ifndef MINISHELL_H
# define MINISHELL_H
# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>
# include <signal.h>
# define PROMPT ">> "
# define DQUOTE "<dquote> "
# define NAME "minishell"

extern t_array_wrap *g_envars;

int		ft_setenv(char *name, char *value, int overwrite);
int		ft_unsetenv(char *name);
void	ft_cd(char **args);
int		ft_echo(char *line);
int		ft_exit(char **args);
int		ft_run(char **args);
void	ft_ls(char **args);
void	ft_pwd(char **args);

int		ft_setenv_check(char **args);
int		ft_unsetenv_check(char **args);
int		ft_echo_check(char **args);
char	*ft_getenv(char *item);
int		check_permission(char *path, int mode);

#endif
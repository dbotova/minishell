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
extern t_array_wrap	*g_paths;
extern t_list		*g_cd_history;

typedef int(*p_func)(char**);

int		ft_setenv(char *name, char *value, int overwrite);
int		ft_unsetenv(char *name);
int		ft_cd(char **args);
int		ft_echo(char **args);
int		ft_exit(char **args);
int		ft_run(char **args);

int		ft_setenv_check(char **args);
int		ft_unsetenv_check(char **args);
int		ft_echo_check(char **args);
char	*ft_getenv(char *item);
int		ft_check_permission(char *path, int mode);
char 	*ft_get_full_path(char *path, char *name);
char	*ft_realpath(const char *path, char *resolved_path);

#endif
#include "minishell.h"

t_array_wrap *g_envars = NULL;

static void free_double_array(char **array) //move to libft
{
   int i;

   i = 0;
   while (array[i])
   {
      SMART_FREE(array[i]);
      i++;
   }
   SMART_FREE(array);
}

static void init_setup(char **envp)
{
	g_envars = (t_array_wrap*)malloc(sizeof(t_array_wrap));
	init_array(&g_envars, SIZE_BLOCK);
   	copy_array(g_envars, envp);
   	system("clear");
}

static char **get_args(char *command)
{
   char **args;
   char  *options;

   args = (char**)malloc(sizeof(char*) * 3);
   options = ft_strchr(command, ' ');
   if (options)
   {
      options++;
      args[0] = (char*)malloc(sizeof(char) * (options - command));
      ft_memset(args[0], 0, sizeof(char) * (options - command));
      args[0] = ft_strncpy(args[0], command, options - command - 1);
      args[1] = ft_strdup(options);
   }
   else
   {
      args[0] = ft_strdup(command);
      args[1] = NULL;
   }
   args[2] = NULL;
   return (args);

}

static int hash_key(char *str)
{
   int key = 0;
   while (*str)
      key += *str++;
   return ((key / 10) - (key % 10));
}

static void debug(void)
{
   ft_printf("env: %d\n", hash_key("env"));
   ft_printf("unset: %d\n", hash_key("unset"));
   ft_printf("export: %d\n", hash_key("export"));
   ft_printf("cd: %d\n", hash_key("cd"));
   ft_printf("pwd: %d\n", hash_key("pwd"));
   ft_printf("echo: %d\n", hash_key("echo"));
   ft_printf("exit: %d\n", hash_key("exit"));
   ft_printf("ls: %d\n", hash_key("ls"));

   ft_printf("cat: %d\n", hash_key("cat"));
}

static int parse_commands(char **commands)
{
   char **args;
   char  *cur_command;

   while (*commands)
   {
      cur_command = ft_strtrim(*commands);
      args = get_args(cur_command);
      SMART_FREE(cur_command);
      if (ft_strcmp(args[0], "env") == 0 && !args[1])
        print_elements(g_envars);
      else if (ft_strcmp(args[0], "unset") == 0)
         ft_unsetenv_check(args);
      else if (ft_strcmp(args[0], "export") == 0)
         ft_setenv_check(args);
      else if (ft_strcmp(args[0], "cd") == 0)
         ft_cd(args);
      else if (ft_strcmp(args[0], "echo") == 0)
         ft_echo_check(args);
      else if (ft_strcmp(args[0], "exit") == 0)
         return (ft_exit(args));
      else if (ft_strcmp(args[0], "pwd") == 0)
         ft_pwd(args);
      else if (ft_strcmp(args[0], "debug") == 0) //remove
         debug();
      else if (ft_strcmp(args[0], "ls") == 0)
         ft_ls(args);
      else if (ft_run(args) == -1)
         ft_putstr_fd("No such file or directory\n", 2);
      commands++;
      free_double_array(args);
   }
   return (0);
}

int main(void)
{
	char *line;
	char **commands;
   extern char **environ;

	line = NULL;
   init_setup(environ);
	while (42)
	{
      ft_printf(PROMPT);
      get_next_line(0, &line);
      commands = ft_strsplit(line, ';');
      if (commands)
      {  
         if (parse_commands(commands))
            break ;
         free_double_array(commands);
      }
      SMART_FREE(line);
	}
	free_array(g_envars);
	SMART_FREE(line);
	return 0;
}
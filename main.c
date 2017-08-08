#include "minishell.h"

t_array_wrap   *g_envars = NULL;
t_array_wrap   *g_paths = NULL;
t_list         *g_cd_history = NULL;

static void init_setup()
{
   extern char **environ;

	init_array(&g_envars, SIZE_BLOCK);
	copy_array(g_envars, environ);
	system("clear");
}

// static char **get_args(char *command)
// {
//    char **args;
//    char  *options;

//    args = (char**)malloc(sizeof(char*) * 3);
//    options = ft_strchr(command, ' ');
//    if (options)
//    {
//       options++;
//       args[0] = (char*)malloc(sizeof(char) * (options - command));
//       ft_memset(args[0], 0, sizeof(char) * (options - command));
//       args[0] = ft_strncpy(args[0], command, options - command - 1);
//       args[1] = ft_strdup(options);
//    }
//    else
//    {
//       args[0] = ft_strdup(command);
//       args[1] = NULL;
//    }
//    args[2] = NULL;
//    return (args);

// }

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

static   char *ft_append_path(char *location, char *name)
{
   char *result;

   result = ft_strjoin(location, "/");
   result = ft_strjoin(result, name);
   return (result);
}

static int parse_commands(char **commands)
{
   char **args;
   char  *cur_command;

   while (*commands)
   {
      cur_command = ft_strtrim(*commands);
      //args = get_args(cur_command);
      args = ft_strsplit(cur_command,' ');
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
         //ft_echo_check(args);
         ft_echo(args[1]);
      else if (ft_strcmp(args[0], "exit") == 0)
         return (ft_exit(args));
      else if (ft_strcmp(args[0], "debug") == 0) //remove
         debug();
      else //fix all leaks and clean up
      {
         int result = -1;
         char *old = ft_strdup(args[0]);
         if (!g_paths)
            break ;
         for (int i = 0; g_paths->data[i]; i++)
         {
            if (result == 0)
               break ;
            SMART_FREE(args[0]);
            args[0] = ft_strdup(ft_append_path(g_paths->data[i], old));
            result = ft_run(args);
         }
         if (result == -1)
         {
            SMART_FREE(args[0]);
            args[0] = ft_strdup(old);
            if (ft_run(args) == -1)
               ft_putstr_fd("No such file or directory\n", 2);
         }
         SMART_FREE(old);
      }
      commands++;
      free_double_array(args);
   }
   return (0);
}

static void clean_up(void)
{
   free_array(g_envars);
   free_array(g_paths);
   ft_lstdel(&g_cd_history, ft_del);
}

int main(void)
{
	char *line;
	char **commands;

   init_setup();
   line = NULL;
   commands = NULL;
	while (42)
	{
      ft_printf(PROMPT);
      get_next_line(0, &line);
      commands = ft_strsplit(line, ';');
      str_to_array(&g_paths, ft_getenv("PATH"), ':');
      if (commands)
      {  
         if (parse_commands(commands))
            break ;
         free_double_array(commands);
         free_array(g_paths);
         g_paths = NULL;
      }
      SMART_FREE(line);
	}
	clean_up();
   SMART_FREE(line);
	return 0;
}
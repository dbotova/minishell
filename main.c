#include "minishell.h"

t_array_wrap *g_envars = NULL;

static void init_setup(char **envp)
{
	g_envars = (t_array_wrap*)malloc(sizeof(t_array_wrap));
	init_array(&g_envars, SIZE_BLOCK);
   	copy_array(g_envars, envp);
   	system("clear");
}

static int parse_commands(char **commands)
{
   char *space;

   space = NULL;
   while (*commands)
   {
      *commands = ft_strtrim(*commands);
      space = ft_strstr(*commands, " ");
      if (ft_strncmp(*commands, "env", space - *commands) == 0 && !space)
        print_elements(g_envars);
      else if (ft_strncmp(*commands, "unset", space - *commands) == 0)
         ft_unsetenv(space + 1);
      else if (ft_strncmp(*commands, "export", space - *commands) == 0) //print env if no arguments
         //add_element(g_envars, space + 1); //ft_setenv
         ft_export(space ? space + 1 : space);
      else if (ft_strncmp(*commands, "exit", space - *commands) == 0)
         return (1);
      commands++;
   }
   return (0);
}

int main(int argc, char **argv, char **envp)
{
	char *line;
	char **commands;

	line = NULL;
	commands = NULL;
	init_setup(envp);
	while (42)
	{
      ft_printf(">> ");
      get_next_line(0, &line);
      commands = ft_strsplit(line, ';');
      if (parse_commands(commands))
         return (0);
      for (int i = 0; commands[i]; i++)
         SMART_FREE(commands[i]);
      SMART_FREE(line);
	}

   	// printf("\n\n\nADD TEST\n\n\n");
   	// ft_setenv("TEST", "1234", 1);
   	// //add_element(g_envars, "TEST=1234");
   	// print_elements(g_envars);


   	// printf("\n\n\nDELETE TERM_PROGRAM\n\n\n");
   	// ft_unsetenv("TERM_PROGRAM");
   	// //delete_element(g_envars, "TERM_PROGRAM");
   	// print_elements(g_envars);

   	// printf("\n\n\nUPDATE HOME\n\n\n");
   	// ft_setenv("HOME", "HOME SWEET HOME", 1);
   	// print_elements(g_envars);

   	// printf("\n\n\nDELETE HOME\n\n\n");
   	// ft_unsetenv("HOME");
   	// //delete_element(g_envars, "HOME");
   	// print_elements(g_envars);

   	// printf("\n\n\nDELETE TEST\n\n\n");
   	// ft_unsetenv("TEST");
   	// //delete_element(g_envars, "TEST");
   	// print_elements(g_envars);

   	// printf("\n\n\nUPDATE HOME\n\n\n");
   	// ft_setenv("HOME", "HOME SWEET HOME", 1);
   	// print_elements(g_envars);
   	

   	//free commands
   	free_array(g_envars);
   	SMART_FREE(line);
   	return 0;
}
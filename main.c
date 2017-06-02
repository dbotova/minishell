#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	g_envars = (t_array_wrap*)malloc(sizeof(t_array_wrap));
	init_array(&g_envars, SIZE_BLOCK);

   	// for (int i = 0; envp[i]; i++)
   	//  	printf("%s\n", envp[i]);

   	copy_array(g_envars, envp);
   	// print_elements(g_envars);


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
   	

   	if (argc > 1)
   	{
   		chdir(argv[1]);
   		system("env");
   	}

   	//system("ls");
   	free_array(g_envars);
   	return 0;
}
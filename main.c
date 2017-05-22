#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	char *curdir;

	curdir = (char*)malloc(sizeof(char) * PATH_MAX);
	ft_memset(curdir, 0, sizeof(char) * PATH_MAX);

	
	t_array_wrap *envars = (t_array_wrap*)malloc(sizeof(t_array_wrap));
	init_array(&envars, SIZE_BLOCK);
	copy_array(envars, envp);

   	for (int i = 0; envp[i]; i++)
   	 	printf("%s\n", envp[i]);


   	printf("\n\n\nCOPY\n\n\n");

   	print_elements(envars);

   	add_element(envars, "TEST=1234");

   	 	printf("\n\n\nADD\n\n\n");

   	print_elements(envars);

   	delete_element(envars, "TERM_PROGRAM");

   	 	printf("\n\n\nDELETE\n\n\n");

   	print_elements(envars);

   	//chdir(argv[1]);

   	//system("ls");
   	free_array(envars);
   	return 0;
}
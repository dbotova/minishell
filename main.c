#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	char *curdir;

	curdir = (char*)malloc(sizeof(char) * PATH_MAX);
	ft_memset(curdir, 0, sizeof(char) * PATH_MAX);

	
	t_array_wrap *envars = (t_array_wrap*)malloc(sizeof(t_array_wrap));
	init_array(&envars, SIZE_BLOCK);

   	for (int i = 0; envp[i]; i++)
   	 	printf("%s\n", envp[i]);


   	printf("\n\n\nCOPY\n\n\n");
   	copy_array(&envars, envp);
   	print_elements(envars);


   	printf("\n\n\nADD TEST\n\n\n");
   	add_element(&envars, "TEST=1234");
   	print_elements(envars);


   	printf("\n\n\nDELETE TERM_PROGRAM\n\n\n");
   	delete_element(envars, "TERM_PROGRAM");
   	print_elements(envars);

   	printf("\n\n\nUPDATE HOME\n\n\n");
   	edit_element(envars, "HOME", "HOME SWEET HOME", '=');
   	print_elements(envars);

   	printf("\n\n\nDELETE HOME\n\n\n");
   	delete_element(envars, "HOME");
   	print_elements(envars);

   	printf("\n\n\nDELETE TEST\n\n\n");
   	delete_element(envars, "TEST");
   	print_elements(envars);
   	
   	if (argc > 1)
   		chdir(argv[1]);

   	//system("ls");
   	SMART_FREE(curdir);
   	free_array(envars);
   	return 0;
}
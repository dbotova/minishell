#include "minishell.h"

static unsigned int mix(unsigned int internal_state, unsigned int message_block)
{
   return (internal_state * message_block) ^
          ((internal_state << 3) + (message_block >> 2));
}

unsigned int hash(char *message)
{
	unsigned int internal_state = MAGIC_NUMBER;
	unsigned int message_block = 0;
	size_t message_length = strlen(message);

   // Loop over the message 32-bits at-a-time
	while (message_length >= 4)
	{
		memcpy(&message_block, message, sizeof(unsigned int));

		internal_state = mix(message_block, internal_state);
		message_length -= sizeof(unsigned int);
		message        += sizeof(unsigned int);
	}

   // Are there any remaining bytes?
	if (message_length)
	{
		memcpy(&message_block, message, message_length);
		internal_state = mix(message_block, internal_state);
	}

	return internal_state % 10;
}

int main(int argc, char **argv, char **envp)
{
	int i = 0;

   	for (; envp[i]; i++)
  	{
   	 	printf("%s\n", envp[i]);
   	}

   	printf("\n\n\n\n");
   	printf("exit: %u\n", hash("exit"));
   	printf("cd: %u\n", hash("cd"));
   	printf("echo: %u\n", hash("echo"));
   	return 0;
}
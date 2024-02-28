#include "shell.h"
/**
* exit_shell - allows shell to exit
*/
void exit_shell(void)
{
	exit(EXIT_SUCCESS);
}

/**
* env_shell - Display the environment variables.
*/
void env_shell(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		/* Use _putchar to print each character in the environment variable */
		char *currentEnvVar;

		currentEnvVar = *env;
		while (*currentEnvVar != '\0')
		{
			_putchar(*currentEnvVar);
			currentEnvVar++;
		}
		/* Move to the next environment variable */
		env++;
		/* Print a new line after each environment variable */
		_putchar('\n');
	}
}

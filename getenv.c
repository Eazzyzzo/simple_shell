#include "shell.h"
/**
* _getenv - prints the environment variable
* @name: the variable
* Return: pointer to (env_name + 1), or NULL if not found
*/

char *_getenv(const char *name)
{
	char **env_ptr = environ;
	char *env_name;
	const char *name_ptr;

	/* Iterate through each environment variable */
		while (*env_ptr != NULL)
		{
			env_name = *env_ptr;
			name_ptr = name;

			/* Check if the current environment variable matches the given name */
				while (*env_name && *name_ptr && *env_name == *name_ptr)
				{
					env_name++;
					name_ptr++;
				}

				/* If both strings have reached their ends, it means we have a match */
				if (*env_name == '=' && *name_ptr == '\0')
				{
				/*Return the address pointing to the environment variable */
					return (env_name + 1);
				}

				env_ptr++;
		}
		/* If the environment variable is not found, return NULL */
	return (NULL);
}

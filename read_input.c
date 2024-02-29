#include "shell.h"
/**
 * read_string - records the input
 * Return: the inputed string
 *
 */

char *read_string(void)
{
	char *readline = NULL;
	size_t n = 0;
	ssize_t getline_return = 0;

	getline_return = getline(&readline, &n, stdin);
	if (getline_return == -1)
	{
		if (feof(stdin))
		{
			/*exit at EOF*/
			free(readline);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("error in getline function");
			free(readline);
			exit(EXIT_FAILURE);
		}
	}
	return (readline);
}

#include "shell.h"
/**
* non_interactive - Handle non-interactive mode.
* @argv: Array of command arguments.
* @delim: Delimiter for string tokenization.
* @input_string: Input string to be tokenized.
*/
void non_interactive(char *argv[], char *delim, char *input_string)
{
	int i;
	/*Non-interactive mode*/
	/*Read and execute each line from the file*/
	while ((input_string = read_string()) != NULL)
	{
		string_tok(input_string, delim, &argv);
		if (argv && argv[0])
		{
			execute(argv);
		}
		else
		{
			perror("Error: No command provided.\n");
		}
		free(input_string);

		/*Free allocated memory*/
		for (i = 0; argv[i] != NULL; i++)
		{
			free(argv[i]);
		}
		free(argv);
	}
}

#include "shell.h"
/**
 * main - entry point
 * @argc: argument count
 * @argv: array of strings
 * Return - zero
*/

int main(int argc, char *argv[])
{
	int i;
	char *delim = " \t\n";
	char *input_string = NULL;
	ssize_t write_result = 0;
	(void)argc;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			/*printing the dollar prompt and a space*/
			write_result = write(STDOUT_FILENO, "$ ", 2);
			if (write_result == -1)
			{
				perror("error in write function");
				exit(EXIT_FAILURE);
			}
			input_string = read_string();
			/* Call the string_tok function to tokenize the input string */
			string_tok(input_string, delim, &argv);
			free(input_string);
			execute(argv);
			/*free command_argv*/
			for (i = 0; argv[i] != NULL; i++)
			{
				free(argv[i]);
			}
			free(argv);
			}
		}
		else
		{
			non_interactive(argv, delim, input_string);
		}
	return (0);
}

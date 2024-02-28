#include "shell.h"
/**
* _error_output - handles errors
* @argv : array of strings
* Returns - nothing
*/
void _error_output(char *argv[])
{
	int last_arg_index = 0;
	char *full_cmd;
	char *shell_path;

	while (argv[last_arg_index + 1] != NULL)
	{
		last_arg_index++;
	}
	/* Command not found, use write for error output */
	full_cmd = _strdup(argv[last_arg_index]);
	shell_path = _strdup(argv[0]);
	if (write(2, shell_path, _strlen(shell_path)) == -1 ||
			write(2, ": ", 2) == -1 ||
			write(2, full_cmd, _strlen(full_cmd)) == -1 ||
			write(2, ": not found\n", 12) == -1)
	{
	/* Handle write error */
		perror("write error");
	}
	free(full_cmd); /*Free memory allocated by _strdup*/
	free(shell_path); /*Free memory allocated by _strdup*/
return;
}


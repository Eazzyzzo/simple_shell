#include "shell.h"
/**
* execute - executes commands
* @argv: array of strings
* Returns - nothing
*/
void execute(char *argv[])
{
	int execve_return = 0;
	char *locate = NULL;
	char *cmd = NULL;
	pid_t pid;

	if (argv && argv[0])
	{
		cmd = argv[0]; /* get the command */
		if (_strcmp(cmd, "exit") == 0)
			exit_shell();
		else if (_strcmp(cmd, "env") == 0)
			env_shell();
		else
		{
			locate = get_locate(cmd);
			if (locate == NULL)
			{
				_error_output(argv);
				exit(EXIT_FAILURE);
			}
			pid = fork();
			if (pid == -1)
			{
				perror("error in fork");
				exit(EXIT_FAILURE);
			}
			if (pid == 0)
			{ /* child process */
				execve_return = execve(locate, argv, NULL);
				if (execve_return == -1)
				{
					perror("error in execve");
					exit(EXIT_FAILURE);
				}
			}
			else /* parent process */
				wait(NULL);
			free(locate);
		}
	}
}

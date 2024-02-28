#include "shell.h"
/**
* get_locate - gets the location of the command
* @cmd: the command to check for
* Return: -the path to the command location
*/
char *get_locate(char *cmd)
{
	char *path;
	char *path_copy;
	int cmd_len;
	char *path_token;
	int dir_len;
	char *file_path = NULL;
	struct stat container;

	path = _getenv("PATH");
	path_copy = _strdup(path);
	path_token = strtok(path_copy, ":");
	cmd_len = _strlen(cmd);

	while (path_token != NULL)
	{
		dir_len = _strlen(path_token);
		file_path = malloc(dir_len + cmd_len + 2);/*plus 2 for slash and NULL*/
		if (file_path == NULL)
		{
			perror("error in file_path return");
			exit(EXIT_FAILURE);
		}
		_strcpy(file_path, path_token);
		_strcat(file_path, "/");
		_strcat(file_path, cmd);

		if (stat(file_path, &container) == 0)
		{
			free(path_copy);
			return (file_path);
		}
		free(file_path);
		path_token = strtok(NULL, ":");
	}
	free(path_copy);
	if (stat(cmd, &container) == 0)
	{
		return (_strdup(cmd));
	}
	return (NULL);
}

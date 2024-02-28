#include "shell.h"
/**
 * string_tok - processes and tokenizes the input
 * @argv: pointer to an array of strings
 * @delim: delimiter
 * @input_string: string to tokenize
 * Returns - nothing
*/
void string_tok(char *input_string, char *delim, char ***argv)
{
	int i = 0;
	char *token = NULL;
	int token_count = 0;
	char *input_string_copy1 = NULL;
	char *input_string_copy2 = NULL;

	input_string_copy1 = _strdup(input_string);
	input_string_copy2 = _strdup(input_string);
	/* Split string into an array of words */
	token = strtok(input_string_copy1, delim);
	/* Count the number of tokens */
	while (token != NULL)
	{
		token_count++;
		token = strtok(NULL, delim); /*NULL for subsequent use*/
	}
	/* Allocate space to store the array of strings */
	*argv = malloc(sizeof(char *) * (token_count + 1)); /*plus NULL terminator*/
	if (*argv == NULL)
	{
		perror("error in memory allocation");
		exit(EXIT_FAILURE);
	}
	/* Store each token in the array */
	token = strtok(input_string_copy2, delim);
	while (token != NULL)
	{
		(*argv)[i] = malloc((_strlen(token) + 1) * sizeof(char));
		_strcpy((*argv)[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	(*argv)[i] = NULL;
/* Free memory */
	free(input_string_copy1);
	free(input_string_copy2);
}

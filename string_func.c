#include "shell.h"
/**
	* _strlen - returns the length of a string
	* @s: string
	* Return: returns length as integer;
	*/

int _strlen(char *s)
{
	int len = 0;

	while (*(s + len) != '\0')
		len++;
	return (len);
}

/**
* _strcpy - Copy paste string
* @dest: destination
*
* @src: source
*
* Return: destination
*/

char *_strcpy(char *dest, char *src)
{
	int inc = 0;

	while (*(src + inc) != '\0')
	{
		*(dest + inc) = *(src + inc);
		inc++;
	}
	*(dest + inc) = '\0';
	return (dest);
}
/**
	* _strdup -> string duplicator function
	* @str: string to be dupliated
	* Return: a string pointer
	*/
char *_strdup(char *str)
{
	int i = 1, j = 0;
	char *s;

	if (str == NULL)
		return (NULL);

	while (str[i])
		i++;
	s = (char *)malloc(i * sizeof(char) + 1);
	if (s == NULL)
	{
		perror("error in memory allocation");
		exit(EXIT_FAILURE);
	}

	while (j < i)
	{
		s[j] = str[j];
		j++;
	}
	s[j] = '\0';

	return (s);
}
/**
	* _strcat - function commute srtings
	* @dest: param pointer to a char
	* @src: param pointer to a char
	* Return: return value of dest
	*/
char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
	* _strcmp - compares two strings
	* @s1: first string.
	* @s2: second string.
	* Return: 0 if s1 and s2 are equals,
	* another number if not.
	*/

int _strcmp(char *s1, char *s2)
{
	int i = 0, op = 0;

	while (op == 0)
	{
		if ((*(s1 + i) == '\0') && (*(s2 + i) == '\0'))
			break;
		op = *(s1 + i) - *(s2 + i);
		i++;
	}
	return (op);
}

#include "main.h"

/**
 * _strcat - concatenate two strings
 * @dest: cahr pointer the dest of thecopied str
 * @src: const char pointer the source of str
 * Return: the dest
 */
char *_strcat(char *dest, const char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * *_strcpy - copies of the string pointd to by src
 * @dest: ...
 * @src: ...
 * Return: the dest
 */
char *_strcpy(char *dest, char *src)
{
	size_t a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';

	return (dest);
}
/**
 * _strcmp - Funcion that compares two strings
 * @s1: type str compared
 * @s2: type str ompared
 * Return: always 0
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;

	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}
/**
 * _strchr - locates a character in a string
 * @s: string
 * @c : character
 * Return: the pointerto the first occurence of the character c
 */
char *_strchr(char *s, char c)
{
	unsigned int i = 0;

	for (; *(s + 1) != '\0'; i++)
		if (*(s + i) == c)
			return (s + i);
	if (*(s + i) == c)
		return (s + i);
	return ('\0');
}
/**
 * _strspn - gets the length of a prefix substring
 * @s: ...
 * @accept: ...
 * Return: the number of accepted bytes
 */
int _strspn(char *s, char *accept)
{
	int i, j, bool;

	for (i = 0; *(s + 1) != '\0'; i++)
	{
		bool = 1;
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(s + i) == *(accept + j))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (1);
}

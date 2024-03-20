#include "main.h"
/**
 * _strcmp - compares two string
 * @string1: first string
 * @string2: second string
 * Return: return 1 if true and 0 on fail
*/
int _strcmp(char *string1, char *string2)
{
	int num;

	for (num = 0; string1[num] != '\0'; num++)
	{
		if (string1[num] != string2[num])
			return (0);
	}
	return (1);
}

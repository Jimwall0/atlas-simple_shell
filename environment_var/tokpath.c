#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "env-main.h"

/**
 * tokpath - tokenizes the environment variable PATH
 * @head: pointer to the head of a linked list
 * @env_val: the PATH value of the environment variable
 *
 * To call function, be sure to set call function "head" to NULL
 *
 * Return: list of tokens for path
*/

path_t *tokpath(path_t **head, char *env_val)
{
	path_t *tmp, *newNode;
	char *token;

	token = strtok(env_val, ":");
	while (token != NULL)
	{
		newNode = malloc(sizeof(path_t));
		if (newNode == NULL)
			return (NULL);
		newNode->dir = strdup(token);
		if (newNode->dir == NULL)
			{
				free(newNode);
				return (NULL);
			}
		newNode->prev = NULL;
		newNode->next = NULL;

		if (*head == NULL)
			*head = newNode;
		else
		{
			tmp = *head;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = newNode;
			newNode->prev = tmp;
		}
		token = strtok(NULL, ":");
	}
	return (*head);
}

/* When used please free list in calling function */
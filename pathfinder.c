#include "main.h"

/**
 * _getenv - gets an environment variable
 * @name: name of variable to find
 * 
 * Return: name=value
*/

char *_getenv(const char *name)
{
	char *env_var, *env_name, *env_val;
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		env_var = environ[i];
		env_name = strtok(env_var, "=");
		env_val = strtok(NULL, "=");
		if (strcmp(env_name, name) == 0)
			return(strdup(env_val));
	}
	return (NULL);
}

/**
 * pathlist - tokenizes the environment variable PATH
 * @head: pointer to the head of a linked list
 *
 * To call function, be sure to set call function "head" to NULL
 *
 * Return: list of tokens for path
*/

path_t *pathlist(path_t **head)
{
	path_t *tmp, *newNode;
	char *env_val = NULL;
	char *token;

	env_val = _getenv("PATH"); /*string of PATHs*/
	token = strtok(env_val, ":");/*tokenize string*/
	while (token != NULL)
	{
		newNode = malloc(sizeof(path_t));
		if (newNode == NULL)
			return (NULL);
		newNode->dir = strdup(token);
		if (newNode->dir == NULL)
			{
				free(env_val);
				free(newNode);
				freelist(head);
				return (NULL);
			}
		newNode->next = NULL;

		if (*head == NULL)
			*head = newNode;
		else
		{
			tmp = *head;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = newNode;
		}
		token = strtok(NULL, ":");
	}
	free(env_val);
	return (*head);
}

/**
 * freelist - frees a list
 * @head: pointer to head of list
 * 
 * use "&" to send address of head
 * Return: n/a
*/

void freelist(path_t **head)
{
	path_t *tmp;

	if (head == NULL)
		return;
	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp->dir);
		free(tmp);
	}
	*head = NULL;
}

/**
 * pathfinder - finds a command path
 * @head: pointer to the head of a list
 * @cmd: command to find
 * 
 * Return: cmdpath on success, error string on failure
*/

char *pathfinder(path_t *head, char *cmd)
{
	path_t *tmp;
	char *cmd_path = NULL;
	char cmd_name[BUFF_SIZE];

	if (strcmp(cmd, "exit") == 0)
		return (cmd);

	sprintf(cmd_name, "/%s", cmd); /*print cmd_name with / in front*/

	tmp = head;
	while (tmp->next != NULL) /*search list for command file*/
	{
		cmd_path = malloc(strlen(tmp->dir) + strlen(cmd_name) + 1);
		if (cmd_path == NULL)
			return (NULL);
		strcpy(cmd_path, tmp->dir);
		strcat(cmd_path, cmd_name);

		if (access(cmd_path, F_OK) == 0) /*check if command file exist at path*/
		{
			free(cmd);
			return (cmd_path);
		}
		else
		{
			free(cmd_path);
			tmp = tmp->next;
		}
	}
	printf("%s: not found\n", cmd);
	free(cmd);
	return (NULL);
}

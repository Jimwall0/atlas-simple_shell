#include "main.h"
/**
 * main - our big function to begin the code
 * Return: returns 0 on success
*/
int main(void)
{
	char *b = NULL, *tok;
	size_t size = 32;
	pid_t pid;

	/* Set up a loop to continuasly recieve user input*/
	b = malloc(sizeof(char) * size);
	if (b == NULL)
		exit(EXIT_FAILURE);
	printf("Insert your command\n");
	getline(&b, &size, stdin);
	tok = strtok(b, " \n");
	/* Duplicate the process*/
	pid = fork();
	/* Child process*/
	if (pid == 0)
	{
		printf("I'm the child process\n");
		sleep(3);
		exit(EXIT_SUCCESS);
	}
	/* This is the main process*/
	wait(NULL);
	printf("I'm the parent proccess\nThis is the token [%s]\n", tok);
	free(b);
	return (0);
}

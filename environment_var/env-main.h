#ifndef _ENV_MAIN_H
#define _ENV_MAIN_H

/* structs */

/**
 * struct path_s - DLL of path tokens
 * @prev: points to previous token
 * @dir: directory value
 * @next: points to next token
*/

typedef struct path_s
{
	char *dir;
	struct path_s *prev;
	struct path_s *next;
} path_t;

/* Prototypes */

char *_getenv(const char *name);
path_t *tokpath(path_t **head, char *name);
int _setenv(const char *name, const char *value, int overwrite);
int addenv(char *new_var);

#endif
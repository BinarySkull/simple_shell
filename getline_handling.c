#include "main.h"

/**
 * parse_input - Splits a command line into arguments.
 * @line: Input string to tokenize.
 *
 * Return: Array of argument strings (NULL-terminated), or NULL on failure.
 *         Memory for each token and the array must be freed with free_args().
 */
char** parse_input(char *line)
{
    char** args;
    char* arg;
    int i = 0, len;

    len = _strlen(line);
    args = malloc(sizeof(char *) * (len / 2 + 2));
    if(!args)
    {
        perror("malloc");
        return NULL;
    }

    arg = strtok(line, " \t\n");

    while(arg != NULL)
    {
        args[i] = _strdup(arg);
        if(!args[i])
        {
            while (i > 0) free(args[--i]);
            free(args);
            perror("malloc");
            return NULL;
        }
        arg = strtok(NULL, " \t\n");
        i++;
    }

    args[i] = NULL;
    return args;
}

/**
 * free_args - Frees memory allocated for an arguments array.
 * @args: NULL-terminated array of strings created by parse_input().
 *
 * Frees each string in the array, then frees the array itself.
 */
void free_args(char **args)
{
    int i = 0;
    if (!args) return;
    while (args[i]) {
        free(args[i]);
        i++;
    }
    free(args);
}
#include "main.h"

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
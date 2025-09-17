#include "main.h"

void exit_func(char **args, char *line, char **env)
{
    if (args[1] != NULL)
    {
        int status = _atoi(args[1]);
        free(line);
        free_args(args);
        exit(status);
    }
    else
    {
        free(line);
        free_args(args);
        exit(EXIT_SUCCESS);
    }
}

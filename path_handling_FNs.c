#include "main.h"

/*
* this file includes functions that handles environment variable and get the path from it
*/

char* get_path(char** environment)
{
    char* path = NULL;
    int len = _strlen("PATH=");
    int i = 0;

    while(environment[i])
    {
        if (_strncmp("PATH=", environment[i], len) == 0)
        {
            path = environment[i] + 5;
            break;
        }
        i++;
    }

    if (!path)
    {
        printf("-bash: PATH: No such file or directory");
        return NULL;
    }

    return path;
}


char* get_check_dir(char*path, char* name) /* don't forget to free the allocated string */
{
    struct stat st;
    char* dir, *full_dir;
    char* cpy_path;
    
    cpy_path = _strdup(path);

    if(!cpy_path)
    {
        perror("strdup");
        return NULL;
    }

    dir = strtok(cpy_path, ":");

    while(dir)
    {
        full_dir = _strjoin(dir, "/", name);
        if (!full_dir)
        {
            perror("malloc");
            free(cpy_path);
            return NULL;
        }
        
        if (stat(full_dir, &st) == 0 && access(full_dir, X_OK) == 0)
        {
            free(cpy_path);
            return full_dir;
        }
        free(full_dir);
        full_dir = NULL;

        dir = strtok(NULL, ":");
    }

    free(cpy_path);
    fprintf(stderr, "sh: %s: not found", name);
    return NULL;
}

char* find_command_dir(char** environment, char* name)
{
    char* path = get_path(environment);
    if (!path)
        return NULL;

    return get_check_dir(path, name);
}
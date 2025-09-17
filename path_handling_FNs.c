#include "main.h"

/**
 * get_path - Retrieves the PATH variable from the environment.
 * @environment: Array of environment variables.
 *
 * Return: Pointer to PATH string (within environment), or NULL if not found.
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

/**
 * get_check_dir - Searches PATH directories for an executable command.
 * @path: PATH string (colon-separated directories).
 * @name: Command name to search for.
 *
 * Return: Newly allocated string with full path to the command if found,
 *         or NULL if not found or on failure.
 * Note: Caller must free the returned string.
 */
char* get_check_dir(char*path, char* name)
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
    fprintf(stderr, "sh: %s: not found\n", name);
    return NULL;
}

/**
 * find_command_dir - Finds the full path of a command using environment PATH.
 * @environment: Array of environment variables.
 * @name: Command name.
 *
 * Return: Full path to command (malloc'ed) if found, or NULL on failure.
 */
char* find_command_dir(char** environment, char* name)
{
    char* path = get_path(environment);
    if (!path)
        return NULL;

    return get_check_dir(path, name);
}
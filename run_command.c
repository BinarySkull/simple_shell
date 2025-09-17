#include "main.h"

/**
 * run_command - Reads a command from stdin and executes it.
 * @env: Array of environment variables.
 *
 * This function:
 *  - Reads user input.
 *  - Resolves the command path (directly or via PATH).
 *  - Parses the input into arguments.
 *  - Forks a child process to run the command with execve().
 *  - Waits for the child process to finish.
 *
 * Frees allocated memory before returning.
 */
void run_command(char** env)
{
    char* dir = NULL, *line = NULL, *if_dir = NULL, *copy_line;
    char **args;
    int status, read;
    size_t len = 0;
    pid_t pid;
    struct stat st;

    read = getline(&line, &len, stdin);

    if (read != -1)
        line[read - 1] = '\0'; 
    
    copy_line = _strdup(line);
    if_dir = strtok(copy_line, " \t\n");
    if (stat(if_dir, &st) == 0 && access(if_dir, X_OK) == 0)
    {
        dir = _strdup(if_dir);
    }
    else
    {
        dir = find_command_dir(env, if_dir);
    }

    free(copy_line);
    args = parse_input(line);
    free(args[0]);
    args[0] = dir;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        free(line);
        free_args(args);
        free(dir);
        return;
    }

    if (pid == 0)
    {
        if (execve(dir, args, env) == -1)
        {
            perror("execve");
            free_args(args);
            free(dir);
            free(line);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        wait(&status);
    }
    free(line);
    free_args(args);
}
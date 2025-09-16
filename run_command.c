#include "main.h"

/*
* the function that executes and runs the command
*/

void run_command(char** env)
{
    char* dir = NULL, *line = NULL;
    char *args[2] = { "ls -l /tmp", NULL };
    int status, read;
    size_t len = 0;
    pid_t pid;
    struct stat st;

            read = getline(&line, &len, stdin);
            if (read != -1)
                line[read - 1] = '\0'; 
            
            if (stat(line, &st) == 0 && access(line, X_OK) == 0)
                dir = line;
            else
                dir = find_command_dir(env, line);
            
            pid = fork();
            if (pid == -1)
            {
                perror("fork");
                free(line);
                if (dir != line)
                    free(dir);
                return;
            }

            if (pid == 0)
            {
                if (execve(dir, args, env) == -1)
                {
                    perror("execve");
                    exit(EXIT_FAILURE);
                }
            }
            else
            {
                wait(&status);
                if (dir != line)
                    free(dir);
                dir = NULL;
            }
            free(line);
}
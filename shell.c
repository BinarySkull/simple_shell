#include "main.h"

/**
 * main - Entry point for the simple shell program.
 * @argc: Argument count (unused).
 * @argv: Argument vector (unused).
 * @env:  Environment variables.
 *
 * Description:
 *   - If running in interactive mode (tty), displays a prompt and repeatedly
 *     calls run_command() to read and execute commands.
 *   - If running in non-interactive mode (e.g., script/pipe), executes once.
 *
 * Return: Always 0 on success.
 */
int main(int argc, char** argv, char** env)
{
    int res;
    (void)argc;
    (void)argv;

    if (isatty(STDIN_FILENO) == 1)
    {
        while(1)
        {
            printf("#cisfun$ ");
            res = run_command(env);
            if (res == 1) /* exit */
                break;
            else if (res == -1) /* EOF */
                break;
        }
    }
    else
    {
        run_command(env);
    }

    return 0;
}

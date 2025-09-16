#include "main.h"

/*
* here will be the main shell function
*/

int main(int argc, char** argv, char** env)
{
    (void)argc;
    (void)argv;

    if (isatty(STDIN_FILENO) == 1)
    {
        while(1)
        {
            printf("#cisfun$ ");
            run_command(env);
        }
    }
    else
    {
        run_command(env);
    }

    return 0;
}

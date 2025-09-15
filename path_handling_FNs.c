#include "main.h"

/*
* this file includes functions that handles environment variable and get the path from it
*/

char* get_path(char* name, char** environment)
{
    char* path;
    int len = _strlen(name);
    int i = 0;

    while(environment[i])
    {
        if (_strncmp(name, environment[i], len))
        {

        }
    }
}
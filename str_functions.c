#include "main.h"

/*
* this file will contain all string functions that will be used in the project
*/


int _strncmp(char *s1, char *s2, int n)
{
    int i = 0;

    while (i < n && s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        i++;
    }

    if (i < n)
        return ((unsigned char)s1[i] - (unsigned char)s2[i]);

    return 0;
}


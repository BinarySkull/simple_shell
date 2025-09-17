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


char *_strdup(char *s)
{
    char *dup;
    int i;
    int len;
    if (s == NULL)
        return NULL;

    len = 0;
    while (s[len] != '\0')
        len++;

    dup = malloc(len + 1);
    if (dup == NULL)
        return NULL;

    for (i = 0; i <= len; i++)
        dup[i] = s[i];

    return dup;
}


char *_strcat(char *dest, char *src)
{
    char *p = dest;

    while (*p != '\0')
        p++;

    while (*src != '\0')
        *p++ = *src++;

    *p = '\0';
    return dest;
}


char *_strjoin(char *a, char *b, char *c) {
    size_t len = strlen(a) + strlen(b) + strlen(c) + 1;
    char *res = malloc(len);
    if (!res) return NULL;
    strcpy(res, a);
    strcat(res, b);
    strcat(res, c);
    return res;
}


/**
 * _strcpy - copies the string pointed to by src to dest
 * @dest: pointer to the destination buffer
 * @src: pointer to the source string
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, const char *src)
{
    char *ptr = dest;

    while ((*dest++ = *src++) != '\0')
        ;

    return ptr;
}
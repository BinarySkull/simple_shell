#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <signal.h>
#include <string.h>
#include <errno.h>


int _strlen(char* str);
char* get_path(char* name, char** environment);
int _strncmp(char *s1, char *s2, int n):



#endif
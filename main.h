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
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *s);
char *_strcat(char *dest, char *src);
char *_strjoin(char *a, char *b, char *c);

char* get_path(char** environment);
char* get_check_dir(char*path, char* name);
char* find_command_dir(char** environment, char* name);

void run_command(char** env);

#endif
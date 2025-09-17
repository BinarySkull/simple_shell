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

/**
 * File: main.h
 * Description: Header file for the simple shell project.
 * Contains library includes and prototypes for all helper
 * functions, organized into logical groups.
 */

/* ========= String utility functions ========= */
int _strlen(char *str);
int _strlen_douple_ptrs(char **str);
int _strncmp(char *s1, char *s2, int n);
int _strcmp(char *s1, char *s2);
char *_strdup(char *s);
char *_strcat(char *dest, char *src);
char *_strjoin(char *a, char *b, char *c);
char *_strcpy(char *dest, const char *src);

/* ========= PATH handling functions ========= */
char *get_path(char **environment);
char *get_check_dir(char *path, char *name);
char *find_command_dir(char **environment, char *name);

/* ========= Input parsing functions ========= */
char **parse_input(char *line);
void free_args(char **args);

/* ========= Command execution ========= */
int run_command(char **env);

#endif /* MAIN_H */
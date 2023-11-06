#ifndef MAIN_H

#define MAIN_H


#include <stdio.h>

#include <unistd.h>

#include <sys/wait.h>

#include <sys/stat.h>

#include <string.h>

#include <stdlib.h>

#include <sys/types.h>

#include <errno.h>

/*extern char **environ;*/


int _strcmp(char *s1, char *s2);

char *_strcpy(char *dest, char *src);

char *_strcat(char *dest, char *src);

size_t _strncmp(char *s1, char *s2, size_t index);

char *_getpath(char **env);

void _getenviron(char **environ);

void exit_cmds(char *av, char **args, char *ptr, int _exit);

int _fork(char **args, char **av, char **environ, char *ptr, int id, int c);

char **token(char *ptr);

int _strlen(char *s);

char *_getline(void);

int pathfind(char **args, char **environ);

char *_strtok(char *str, const char *delimiter);


#endif

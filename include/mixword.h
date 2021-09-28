/*
** EPITECH PROJECT, 2021
** lib
** File description:
** lib
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct mix_s
{
    char **words;
    char **map;
    char *tmp;
    char *file;
    int size;
    int nbw;
    int total;
} mix_t;

int init_params(mix_t *m, int ac, char **av);
int try_open(mix_t *m);
int init(mix_t *m);
void display(mix_t *m);
char **my_strtok(char *str, char delim);
void free_all(mix_t *m);
void load_word(mix_t *m);
char **split(char *str, char c);
int my_strlen(char const *str);

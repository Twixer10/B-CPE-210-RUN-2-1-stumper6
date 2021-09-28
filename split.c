/*
** EPITECH PROJECT, 2021
** split
** File description:
** split
*/

#include <stdlib.h>
#include <stdio.h>
#include "./include/mixword.h"

char *remove_useless_char(char *str, char c)
{
    int i = 0;
    char *fakestr = strdup(str);
    while (str[0] == c)
        str++;
    while (str[i] != '\0') {
        if (str[i] == c && (str[i + 1] == c || str[i + 1] == '\0' ||
        str[i + 1] == '\n'))
            str++;
        else {
            fakestr[i] = str[i];
            i++;
        }
    }
    fakestr[i] = '\0';
    return (fakestr);
}

char **get_words_2(char *str, char **arr, char c)
{
    int i = 0;
    int j = 0;
    int word = 0;

    for (; str[i] != '\0'; i++, j++) {
        if (str[i] == c) {
            arr[word][j + 1] = '\0';
            word++;
            j = 0;
            i++;
        }
        arr[word][j] = str[i];
    }
    arr[word + 1] = NULL;
    return (arr);
}

char **get_words_length_2(char *str, char **arr, char c)
{
    int i = 0;
    int wordslen = 0;
    int word = 0;

    while (str[i] != '\0') {
        if (str[i] == c) {
            arr[word] = malloc(sizeof(char) * wordslen + 1);
            wordslen = -1;
            word++;
        }
        i++;
        wordslen++;
    }
    arr[word] = malloc(sizeof(char) * wordslen + 1);
    return (arr);
}

int get_number_of_words_2(char *str, char c)
{
    int i = 0;
    int spacecount = 0;

    while (str[i] != '\0') {
        if (str[i] == c)
            spacecount++;
        i++;
    }
    return (spacecount + 1);
}

char **split(char *str, char c)
{
    int nbwords;
    char **arr;

    str = remove_useless_char(str, c);
    nbwords = get_number_of_words_2(str, c);
    arr = malloc(sizeof(char *) * (nbwords + 1));
    arr = get_words_length_2(str, arr, c);
    arr = get_words_2(str, arr, c);
    free(str);
    return (arr);
}

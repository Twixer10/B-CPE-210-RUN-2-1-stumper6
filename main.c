/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "./include/mixword.h"

int main(int ac, char **av)
{
    mix_t *m = malloc(sizeof(mix_t));

    m->size = 8;
    m->file = NULL;
    m->map = NULL;
    m->tmp = NULL;
    m->words = NULL;
    if (init_params(m, ac, av) == -1 || try_open(m) == -1 ||
        init(m) == -1) {
        free(m);
        return (84);
    }
    load_word(m);
    display(m);
    free_all(m);
    return (0);
}

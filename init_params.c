/*
** EPITECH PROJECT, 2021
** init params
** File description:
** init params
*/

#include "./include/mixword.h"

void free_all(mix_t *m)
{
    for (int i = 0; m->map[i] != NULL; i++)
        free(m->map[i]);
    for (int i = 0; m->words[i] != NULL; i++)
        free(m->words[i]);
    free(m->words);
    free(m->map);
    free(m->file);
    free(m->tmp);
    free(m);
}

void display(mix_t *m)
{
    printf("%d/%d words inserted in the grid.\n", m->total, m->nbw);
    for (int i = 0; i < m->size + 2; i++)
        putchar('+');
    putchar('\n');
    for (int i = 0; m->map[i] != NULL; i++)
        printf("|%s|\n", m->map[i]);
    for (int i = 0; i < m->size + 2; i++)
        putchar('+');
    putchar('\n');
}

int init(mix_t *m)
{
    int a = 97;

    if ((m->map = malloc(sizeof(char *) * (m->size + 1))) == NULL)
        return (-1);
    for (int i = 0; i != m->size; i++) {
        if ((m->map[i] = malloc(sizeof(char) * (m->size + 1))) == NULL)
            return (-1);
        for (int y = 0; y != m->size; y++, a++) {
            if (a > 'z')
                a = 'a';
            m->map[i][y] = a;
        }
        m->map[i][m->size] = '\0';
    }
    m->map[m->size] = NULL;
    return (0);
}

int try_open(mix_t *m)
{
    int fd;
    struct stat st;

    if (stat(m->file, &st) == -1)
        return (-1);
    if (st.st_size < 2)
        return (-1);
    if ((fd = open(m->file, O_RDONLY)) == -1)
        return (-1);
    if ((m->tmp = malloc(sizeof(char) * st.st_size)) == NULL)
        return (-1);
    if (read(fd, m->tmp, st.st_size) == - 1)
        return (-1);
    return (0);
}

int init_params(mix_t *m, int ac, char **av)
{
    int f = 0;
    int s = 0;

    if (ac < 3 && ac > 5)
        return (-1);
    for (int i = 1; av[i];) {
        if (strcmp(av[i], "-f") == 0 && av[i + 1] != NULL && f == 0) {
            m->file = strdup(av[i + 1]);
            f++;
            i += 2;
        } else if (strcmp(av[i], "-s") == 0 && av[i + 1] != NULL && s == 0) {
            if ((m->size = atoi(av[i + 1])) <= 0)
                return (-1);
            s++;
            i += 2;
        } else {
            return (-1);
        }
    }
    return ((m->file == NULL) ? -1 : 0);
}

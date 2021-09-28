/*
** EPITECH PROJECT, 2021
** word manager
** File description:
** word manager
*/

#include "./include/mixword.h"

void load_word(mix_t *m)
{
    m->words = split(m->tmp, '\n');
    m->nbw = 0;
    m->total = 0;
    for (int i = 0; m->words[i]; i++)
        m->nbw++;
    for (int y = 0; m->words[y]; y++) {
        for (int i = m->total; m->map[i]; i++) {
            if (my_strlen(m->map[i]) >= my_strlen(m->words[y])) {
                for (int z = 0; z != my_strlen(m->words[y]); z++)
                    m->map[i][z] = m->words[y][z];
                m->total++;
            }
            break;
        }
    }
}

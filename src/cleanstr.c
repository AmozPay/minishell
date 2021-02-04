/*
** EPITECH PROJECT, 2021
** Clean String - Solo Stumper
** File description:
** main file
*/

#include "my.h"

static void shift_left(char *str, int pos)
{
    int i = pos;
    int len = my_strlen(str);

    while (i < len) {
        str[i] = str[i + 1];
        i++;
    }
}

static void erase_spaces(char *str, int *i)
{
    while (str[*i] == ' ' && str[(*i) + 1] == ' ')
        shift_left(str, (*i));
    (*i)++;
}

void clean_str(char *str)
{
    int i = 0;

    while (str[i] != '\n') {
        if (str[i] == '\t')
            str[i] = ' ';
        if (str[i] == '\n')
            str[i] = '\0';
        i++;
    }
    str[i] = '\0';
    i = 0;
    while (str[i] == ' ')
        shift_left(str, i);
    while (str[i] != '\0') {
        erase_spaces(str, &i);
        while (str[i] > 32 && str[i] < 127)
            (i)++;
    }
    if (i > 0 && str[i - 1] == ' ')
        str[i - 1] = '\0';
}
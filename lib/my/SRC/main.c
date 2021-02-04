/*
** EPITECH PROJECT, 2020
** my_printf - Amoz PAY
** File description:
** functionnal test file
*/

#include "my.h"

int main(int ac, char **av)
{
    int i = 0;
    int cmpt = 0;
    char salut[6] = {'s', 'a', 'l', 'u', 't', '\0'};

    salut[2] = 20;
    my_printf("%S", salut);
    return (0);
}

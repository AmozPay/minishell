/*
** EPITECH PROJECT, 2020
** my_sprinft - Amoz PAY
** File description:
** Returns a struct with the content of my_printf and nb_strings
*/

#include "my.h"

sprintf_t my_sprintf(char const *format, ...)
{
    sprintf_t new;
    int nb_strings = parsing_count(format);
    char **output = malloc(sizeof(char *) * nb_strings);
    va_list list;

    preload_output(format, output, nb_strings);
    va_start(list, format);
    format_output(list, nb_strings, output);
    va_end(list);
    new.nb_strings = nb_strings;
    new.output = output;
    return (new);
}

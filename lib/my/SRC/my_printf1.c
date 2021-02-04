/*
** EPITECH PROJECT, 2020
** my_printf - Amoz Pay
** File description:
** Formated output conversion
*/

#include "my.h"

int add_conversion(char const *format, int *count, int *i)
{
    if (format[*i] == '\0')
        return (0);
    if (format[*i] == '%' && format[*i + 1] != '\0') {
        (*i)++;
        go_to_next_element(format, i, count);
        return (0);
    } else if (format[*i] == '%' && format[*i + 1] == '\0') {
        (*i)++;
        return (0);
    }
}

int add_str(char const *format, int *count, int *i)
{
    if (format[*i] != '%') {
        (*count)++;
        (*i)++;
        while (format[*i] != '%' && format[*i] != '\0')
            (*i)++;
    }
    return (0);
}

int parsing_count(char const *format)
{
    int count = 0;
    int i = 0;

    while (format[i] != '\0') {
        add_str(format, &count, &i);
        add_conversion(format, &count, &i);
    }
    return (count);
}

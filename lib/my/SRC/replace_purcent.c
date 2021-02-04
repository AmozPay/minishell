/*
** EPITECH PROJECT, 2020
** is_purcent- Amoz PAY
** File description:
** quick function to replace the %% flag
*/

#include "my.h"

int is_purcent(char *format)
{
    int last_digit = my_strlen(format) - 1;

    if (format[last_digit] == '%')
        return (1);
    return (0);
}

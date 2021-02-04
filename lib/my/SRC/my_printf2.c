/*
** EPITECH PROJECT, 2020
** my_printf - Amoz PAY
** File description:
** Formated output conversion
*/

#include "my.h"

int go_to_next_element(char const *format, int *i, int *count)
{
    while (format[*i] != '\0') {
        if (is_conv_spec(format[*i])) {
            (*i)++;
            (*count)++;
            return (0);
        } else if (is_flag(format[*i]) || is_num_or_dot(format[*i])) {
            (*i)++;
        } else
            return (0);
    }
}

int is_conv_spec(char c)
{
    char const *conv_spec = CONV_SPEC;

    for (int j = 0; conv_spec[j] != '\0'; j++)
        if (c == conv_spec[j])
            return (1);
    return (0);
}

int is_flag(char c)
{
    const char *flags = FLAGS;

    for (int j = 0; flags[j] != '\0'; j++)
        if (c == flags[j])
            return (1);
    return (0);
}

int is_num_or_dot(char c)
{
    if (c <= '9' && c >= '0')
        return (1);
    if (c == '.')
        return (1);
    return (0);
}

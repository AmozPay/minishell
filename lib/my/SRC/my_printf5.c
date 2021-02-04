/*
** EPITECH PROJECT, 2020
** my_printf - Amoz PAY
** File description:
** Formatted output conversion
*/

#include "my.h"

int is_nb(char *str)
{
    int last_digit = my_strlen(str) - 1;

    for (int i = 0; CONV_SPEC[i] != 's'; i++)
        if (str[last_digit] == CONV_SPEC[i])
            return (1);
    return (0);
}

int is_convertible(char c)
{
    for (int i = 0; CONV_SPEC[i] != 'd'; i++)
        if (c == CONV_SPEC[i])
            return (1);
    return (0);
}

int is_str(char *str)
{
    int last_digit = my_strlen(str) - 1;

    if (str[last_digit] == 's')
        return (1);
    return (0);
}

char *save_char_str(char *format, int char_as_int)
{
    char *char_str = malloc(sizeof(char) * 2);

    char_str[0] = char_as_int;
    char_str[1] = '\0';
    char_str = process_flags(format, char_str);
    free(format);
    return (char_str);
}

char *replace_str(char *format, char *str)
{
    str = process_flags(format + 1, str);
    free(format);
    return (str);
}

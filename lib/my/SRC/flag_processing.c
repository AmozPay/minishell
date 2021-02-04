/*
** EPITECH PROJECT, 2020
** my_printf - Amoz PAY
** File description:
** Formatted output conversion
*/

#include "my.h"

int find_other_flag(char c)
{
    int i = 0;
    char *flags = FLAGS;

    while (i < 4) {
        if (c == flags[i])
            return (i);
        i++;
    }
}

int is_other_flags(char c)
{
    char *other_flags = FLAGS;

    for (int i = 0; i < 4; i++)
        if (c == other_flags[i])
            return (1);
    return (0);
}

void get_other_flags(char *format, int *flags)
{
    int i = 0;

    while (!is_conv_spec(format[i])) {
        if (is_other_flags(format[i]))
            flags[find_other_flag(format[i])] = 1;
        i++;
    }
}

void get_padding(char *format, int *flags)
{
    int i = 0;
    int j = 0;

    while (!is_conv_spec(format[i])) {
        if (format[i] >= '1' && format[i] <= '9') {
            while (format[i + j] >= '0' && format[i + j] <= '9')
                j++;
            flags[5] = my_getnbr(format + i);
            if (flags[5] < 0)
                flags[5] = flags[5] * (-1);
            i+= j;
        } else if (format[i] == '0') {
            flags[4] = 1;
            i++;
        } else
            i++;
    }
}

char *process_flags(char *format, char *str)
{
    int flags[6] = {0, 0, 0, 0, 0, 0};

    get_padding(format, flags);
    get_other_flags(format, flags);
    if (flags[1] == 1)
        flags[4] = 0;
    if (flags[2] == 1)
        flags[1] = 0;
    if (flags[3] == 1)
        flags[4] = 0;
    str = add_other_flags(str, flags, format);
    if (my_strlen(str) < flags[5])
        str = add_padding(str, flags, format);
    return (str);
}

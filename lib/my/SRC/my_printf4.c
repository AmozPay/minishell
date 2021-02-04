/*
** EPITECH PROJECT, 2020
** my_printf - Amoz PAY
** File description:
** Formatted output conversion
*/

#include "my.h"

char *load_str(char const *format, int *i)
{
    int j = 0;
    char *str;

    if (format[0] != '%') {
        j++;
        while (format[j] != '%' && format[j] != '\0')
            j++;
        (*i)+= j;
        str = malloc(sizeof(char) * (j + 1));
        return (my_strncpy(str, format, j));
    } else {
        return (NULL);
    }
}

char *load_conversion(char const *format, int *i)
{
    int j = 0;
    char *str;
    int useless = 0;

    if (format[j] == '\0')
        return (NULL);
    if (format[j] == '%' && format[j + 1] != '\0') {
        (j)++;
        go_to_next_element(format, &j, &useless);
        str = malloc(sizeof(char) * (j + 1));
        (*i)+= j;
        return (my_strncpy(str, format, j));
    } else if (format[j] == '%' && format[j + 1] == '\0') {
        j++;
        (*i)+= j;
        return (NULL);
    }
}

char *load_output(char const *format, int *i)
{
    if (format[0] == '%')
        return (load_conversion(format, i));
    else if (format[0] != '%' && format[0] != '\0')
        return (load_str(format, i));
    else
        return (NULL);
}

void preload_output(char const *format, char **output, int nb_strings)
{
    int i = 0;
    int j = 0;

    while (j < nb_strings) {
        output[j] = load_output(format + i, &i);
        j++;
    }
}

char *convert_base(char *str, char last_digit, long arg)
{
    char *conversion;

    switch (str[last_digit]) {
    case 'o':
        conversion = my_save_nbr_base(arg, 8);
        break;
    case 'x':
        conversion = my_save_nbr_base(arg, 16);
        break;
    case 'X':
        conversion = my_save_nbr_base(arg, 16);
        conversion = my_strupcase(conversion);
        break;
    case 'b':
        conversion = my_save_nbr_base(arg, 2);
        break;
    }
    return (conversion);
}

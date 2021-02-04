/*
** EPITECH PROJECT, 2020
** my_printf - Amoz PAY
** File description:
** Formatted output conversion
*/

#include "my.h"

char *add_alternate_form_x(char *str, char conv_spec)
{
    char *alternate_form = malloc(sizeof(char) * (my_strlen(str) + 3));

    alternate_form[0] = '0';
    if (conv_spec == 'x')
        alternate_form[1] = 'x';
    else
        alternate_form[1] = 'X';
    my_strcpy(alternate_form + 2, str);
    free(str);
    return (alternate_form);
}

char *add_alternate_form_o(char *str)
{
    char *alternate_form = malloc(sizeof(char) * (my_strlen(str) + 2));

    alternate_form[0] = '0';
    my_strcpy(alternate_form + 1, str);
    free(str);
    return (alternate_form);
}

char *add_space_or_sign(char *str, char conv_spec, char space_or_sign)
{
    char *signed_str;

    if (conv_spec == 'd' || conv_spec == 'i' || conv_spec == 'p') {
        signed_str = malloc(sizeof(char) * (my_strlen(str) + 2));
        signed_str[0] = space_or_sign;
        my_strcpy(signed_str + 1, str);
        free(str);
        return (signed_str);
    }
    return (str);
}

char *add_other_flags(char *str, int *flags, char *format)
{
    int last_digit = my_strlen(format) - 1;

    if (flags[0] == 1) {
        if (format[last_digit] == 'x' || format[last_digit] == 'X')
            str = add_alternate_form_x(str, format[last_digit]);
        if (format[last_digit] == 'o' && format[0] != '0')
            str = add_alternate_form_o(str);
    }
    if (flags[1] == 1 && str[0] != '-')
        str = add_space_or_sign(str, format[last_digit], ' ');
    if (flags[2] == 1 && str[0] != '-')
        str = add_space_or_sign(str, format[last_digit], '+');
    return (str);
}

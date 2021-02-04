/*
** EPITECH PROJECT, 2020
** my_printf - Amoz PAY
** File description:
** Formatted output conversion
*/

#include "my.h"

char *add_padding_sign(int nb_chars_pad, char sign)
{
    char *padding = malloc(sizeof(char) * (nb_chars_pad + 1));

    for (int i = 0; i < nb_chars_pad; i++)
        padding[i] = sign;
    return (padding);
}

int is_not_letter(char c)
{
    if (c <= 'z' && c >= 'a')
        return (0);
    if (c <= 'Z' && c >= 'A')
        return (0);
    return (1);
}

char *add_padding(char *str, int *flags, char *format)
{
    int nb_chars_pad = flags[5] - my_strlen(str);
    int malloc_size = my_strlen(str) + nb_chars_pad + 1;
    char *with_padding = malloc(sizeof(char) * malloc_size);
    char *padding;

    if (flags[3] == 0 && flags[4] == 1 && is_not_letter(str[0]))
        padding = add_padding_sign(nb_chars_pad, '0');
    else
        padding = add_padding_sign(nb_chars_pad, ' ');
    if ((str[0] == '-' || str[0] == '+') && padding[0] == '0') {
        padding[0] = str[0];
        str[0] = '0';
    }
    if (flags[3] == 1)
        with_padding = my_strcat(str, padding);
    else
        with_padding = my_strcat(padding, str);
    return (with_padding);
}

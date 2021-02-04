/*
** EPITECH PROJECT, 2020
** my_printf - Amoz PAY
** File description:
** Formatted output conversion
*/

#include "my.h"

int is_no_print_str(char *format)
{
    int last_digit = my_strlen(format) - 1;

    if (format[last_digit] == 'S')
        return (1);
    return (0);
}

char *replace_no_print(char *format, char *str)
{
    int i = 0;
    char *no_print_char;
    char *strcpy = malloc(sizeof(char) * (my_strlen(str) + 1));

    my_strcpy(strcpy, str);
    while (str[i] != '\0') {
        if (str[i] < 32) {
            no_print_char = my_save_nbr_base(str[i], 8);
            if (my_strlen(no_print_char) == 1)
                no_print_char = my_strcat("/00", no_print_char);
            if (my_strlen(no_print_char) == 2)
                no_print_char = my_strcat("/0", no_print_char);
            strcpy = my_strncat(str, no_print_char, i);
            strcpy = my_strcat(strcpy, str + i + 1);
        }
        i++;
    }
    strcpy = process_flags(format + 1, strcpy);
    return (strcpy);
}

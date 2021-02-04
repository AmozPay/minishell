/*
** EPITECH PROJECT, 2020
** my_printf - Amoz PAY
** File description:
** Formatted output conversion
*/

#include "my.h"

char *convert_int(char *str, int arg)
{
    int last_digit = my_strlen(str) - 1;
    char *conversion;

    if (is_convertible(str[last_digit])) {
        conversion = convert_base(str, last_digit, (long)arg);
    } else if (str[last_digit] == 'c') {
        conversion = malloc(sizeof(char) * 2);
        conversion[0] = arg;
        conversion[1] = '\0';
    } else
        conversion = my_save_nbr_base((long)arg, 10);
    conversion = process_flags(str + 1, conversion);
    free (str);
    return (conversion);
}

int is_ptr(char *format)
{
    int last_digit = my_strlen(format) - 1;

    if (format[last_digit] == 'p')
        return (1);
    return (0);
}

char *replace_ptr(char *format, void *ptr)
{
    char *ptr_address = my_save_u_nbr_base((unsigned long)ptr, 16);
    char *hex_ptr_address = malloc(sizeof(char) * (my_strlen(ptr_address) + 3));

    hex_ptr_address[0] = '0';
    hex_ptr_address[1] = 'x';
    hex_ptr_address = my_strcat(hex_ptr_address, ptr_address);
    hex_ptr_address = process_flags(format + 1, hex_ptr_address);
    return (hex_ptr_address);
}

void format_output(va_list list, int nb_strings, char **output)
{
    int i = 0;

    while (i < nb_strings) {
        if (output[i][0] == '%') {
            if (is_nb(output[i]))
                output[i] = convert_int(output[i], va_arg(list, int));
            if (is_str(output[i]))
                output[i] = replace_str(output[i], va_arg(list, char *));
            if (is_ptr(output[i]))
                output[i] = replace_ptr(output[i], va_arg(list, void *));
            if (is_no_print_str(output[i]))
                output[i] = replace_no_print(output[i], va_arg(list, char*));
            if (is_purcent(output[i]))
                output[i] = "%";
        }
        i++;
    }
}

int my_printf(char const *format, ...)
{
    int nb_strings = parsing_count(format);
    char **output = malloc(sizeof(char *) * nb_strings);
    int cmpt = 0;
    va_list list;

    preload_output(format, output, nb_strings);
    va_start(list, format);
    format_output(list, nb_strings, output);
    va_end(list);
    for (int j = 0; j < nb_strings; j++) {
        cmpt+= my_putstr(output[j]);
    }
    free(output);
    return (cmpt);
}

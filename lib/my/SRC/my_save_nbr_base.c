/*
** EPITECH PROJECT, 2020
** my_put_nbr By Amoz PAY
** File description:
** displays a number in hexadecimal base
*/

#include "my.h"

char *my_save_nbr_base(long nb, int base_spec)
{
    char *str = malloc(sizeof(char) * 65);
    int cmpt = 0;
    char *mem_saving_str;

    for (int i = 0; i < 65; i++)
        str[i] = '\0';
    save_nbr_base(nb, base_spec, str, &cmpt);
    mem_saving_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    my_strcpy(mem_saving_str, str);
    free(str);
    return (mem_saving_str);
}

void save_nbr_base(long nb, int base_spec, char *dest, int *cmpt)
{
    long long nb_long_long = nb;
    char *base_array[16];

    base_array[2] = BIN_BASE;
    base_array[8] = OCT_BASE;
    base_array[10] = DEC_BASE;
    base_array[16] = HEX_BASE;
    if (nb_long_long < 0) {
        dest[*cmpt] = '-';
        (*cmpt)++;
        nb = nb * (-1);
    }
    if (nb < base_spec) {
        dest[*cmpt] = base_array[base_spec][nb];
        (*cmpt)++;
    } else {
        save_nbr_base(nb / base_spec, base_spec, dest, cmpt);
        save_nbr_base(nb % base_spec, base_spec, dest, cmpt);
    }
}

char *my_save_u_nbr_base(unsigned long nb, int base_spec)
{
    char *str = malloc(sizeof(char) * 32);
    int cmpt = 0;
    char *mem_saving_str;

    for (int i = 0; i < 32; i++)
        str[i] = '\0';
    save_nbr_base(nb, base_spec, str, &cmpt);
    mem_saving_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    my_strcpy(mem_saving_str, str);
    free(str);
    return (mem_saving_str);
}

void save_u_nbr_base(unsigned long nb, int base_spec, char *dest, int *cmpt)
{
    char *base_array[16];

    base_array[2] = BIN_BASE;
    base_array[8] = OCT_BASE;
    base_array[10] = DEC_BASE;
    base_array[16] = HEX_BASE;
    if (nb < base_spec) {
        dest[*cmpt] = base_array[base_spec][nb];
        (*cmpt)++;
    } else {
        save_nbr_base(nb / base_spec, base_spec, dest, cmpt);
        save_nbr_base(nb % base_spec, base_spec, dest, cmpt);
    }
}

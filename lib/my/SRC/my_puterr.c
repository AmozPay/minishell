/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-amoz.pay
** File description:
** my_puterr
*/

#include <unistd.h>

int my_strlen(char const *str);

void my_puterr(char const *str)
{
    int len = my_strlen(str);

    write(2, str, len);
}
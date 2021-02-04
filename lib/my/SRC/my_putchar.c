/*
** EPITECH PROJECT, 2020
** my_putchar - Amoz PAY
** File description:
** display a char on standard output
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

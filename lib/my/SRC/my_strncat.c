/*
** EPITECH PROJECT, 2020
** my_strncat - Amoz PAY
** File description:
** Concatenate two strings starting at n byte in string dest
*/

#include <stdlib.h>

int my_strlen(char const *str);
int my_strcpy(char *, char *);

char *my_strncat(char *dest, char *src, int n)
{
    int str_malloc_size = my_strlen(dest + n) + my_strlen(src) + 1;
    char *result = malloc(sizeof(char) * str_malloc_size);
    int i = 0;

    if (n < my_strlen(dest)) {
        my_strcpy(result, dest);
        while (i < n)
            i++;
        my_strcpy(result + i, src);
    }
    return (result);
}

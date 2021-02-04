/*
** EPITECH PROJECT, 2020
** my_strcat - Amoz PAY
** File description:
** concatenate two strings
*/

#include <stdlib.h>

int my_strlen(char const *str);
int my_strcpy(char *, char *);

char *my_strcat(char *dest, char *src)
{
    int str_malloc_size = my_strlen(dest) + my_strlen(src) + 1;
    char *result = malloc(sizeof(char) * str_malloc_size);
    int i = 0;

    if (src == NULL)
        return dest;
    if (dest == NULL)
        return src;
    my_strcpy(result, dest);
    while (result[i] != '\0')
        i++;
    my_strcpy(result + i, src);
    return (result);
}

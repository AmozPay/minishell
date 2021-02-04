/*
** EPITECH PROJECT, 2020
** my strcpy by Amoz PAY
** File description:
** copies a string into another
*/

void *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

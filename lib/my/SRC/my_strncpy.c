/*
** EPITECH PROJECT, 2020
** my strncpy by Amoz PAY
** File description:
** copies n characters from string src to string dest
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (n < 1) {
        return (dest);
    }
    if (n > my_strlen(src)) {
        while (i < my_strlen(src)) {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
        return (dest);
    } else {
        while (i < n) {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
        return (dest);
    }
}

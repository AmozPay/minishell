/*
** EPITECH PROJECT, 2020
** my strncmp by Amoz PAY
** File description:
** compares two strings of n bytes
*/

int my_strlen(char const *str);

int my_strncmp(char const *s1, char const *s2, int n)
{
    if (n < 1)
        return 0;
    for (int i = 0; i < my_strlen(s1) && i < my_strlen(s2) && i < n; i++) {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
    }
    return 0;
}

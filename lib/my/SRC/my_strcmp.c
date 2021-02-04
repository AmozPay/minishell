/*
** EPITECH PROJECT, 2020
** my strcmp by Amoz PAY
** File description:
** compares two strings
*/

int my_strcmp(char const *s1, char const *s2)
{
    if (*s1 == '\0' && *s2 == '\0')
        return (0);
    if (*s1 > *s2 || *s2 == '\0')
        return (1);
    if (*s1 < *s2 || *s1 == '\0')
        return (-1);
    return my_strcmp(s1 + 1, s2 + 1);
}

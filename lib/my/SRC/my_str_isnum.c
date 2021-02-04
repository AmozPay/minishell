/*
** EPITECH PROJECT, 2020
** my str is num by Amoz PAY
** File description:
** returns 1 if a string is strictly numerical or empty
*/

int my_strlen(char const *str);

int my_str_isnum(char const *str)
{
    int i = 0;

    if (my_strlen(str) < 1) {
        return (1);
    }
    while (str[i] != '\0') {
        if (str[i] <'0' || str[i] > '9') {
            return (0);
        }
        i++;
    }
    return (1);
}

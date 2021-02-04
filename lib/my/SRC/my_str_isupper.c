/*
** EPITECH PROJECT, 2020
** my str is upper by Amoz PAY
** File description:
** returns 1 if a string is strictly alphabetical upper case or empty
*/

int my_strlen(char const *str);

int my_isupper(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}

int my_str_isupper(char const *str)
{
    int i = 0;

    if (my_strlen(str) == 0) {
        return (1);
    }
    while (str[i] != '\0') {
        if (my_isupper(str[i]) == 0) {
            return (0);
        }
        i++;
    }
    return (1);
}

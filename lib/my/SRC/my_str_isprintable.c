/*
** EPITECH PROJECT, 2020
** my str isprintable by Amoz PAY
** File description:
** return 1 if a string is strictly printable
*/

int my_strlen(char const *str);

int my_isprintable(char c)
{
    if (c > 31 && c < 127)
        return 1;
    return 0;
}

int my_str_isprintable(char const *str)
{
    int i = 0;

    if (my_strlen(str) < 1) {
        return 1;
    }
    while (str[i] != '\0') {
        if (my_isprintable(str[i]) == 0) {
            return 0;
        }
        i++;
    }
    return 1;
}

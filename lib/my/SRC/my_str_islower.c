/*
** EPITECH PROJECT, 2020
** my str is lower by Amoz PAY
** File description:
** returns 1 if a string is strictly alphabetical lower case or empty
*/

int my_strlen(char const *str);

int my_islower(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

int my_str_islower(char const *str)
{
    int i = 0;

    if (my_strlen(str) == 0) {
        return (1);
    }
    while (str[i] != '\0') {
        if (my_islower(str[i]) == 0) {
            return (0);
        }
        i++;
    }
    return (1);
}

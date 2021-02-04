/*
** EPITECH PROJECT, 2020
** My str upcase by Amoz PAY
** File description:
** Returns a string with lowercase letters
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
        i++;
    }
    return (str);
}

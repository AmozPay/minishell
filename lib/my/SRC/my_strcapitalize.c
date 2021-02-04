/*
** EPITECH PROJECT, 2020
** My strcapitalize by Amoz PAY
** File description:
** capitalizes the 1st letter of each word
*/

char my_c_is_alphanum(char c)
{
    if (c <= 'Z' && c >= 'A')
        return (1);
    if (c >=  'a' && c <= 'z')
        return (1);
    if (c <= '9' && c >= '0')
        return (1);
    return (0);
}

char *my_strcapitalize(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        while (my_c_is_alphanum(str[i]) != 1 && str[i] != '\0') {
            i++;
        }
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
        while (my_c_is_alphanum(str[i + j]) && str[i + j] != '0') {
            j++;
        }
        i += j;
        j = 0;
    }
    return (str);
}

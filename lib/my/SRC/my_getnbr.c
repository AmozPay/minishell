/*
** EPITECH PROJECT, 2021
** my_get_nbr by Amoz PAY
** File description:
** Version 2. Gets an int out of a string parameter.
*/

long check_result_is_long(long long result)
{
    long result_as_an_long = 0;

    if (result >= -9223372036854775807 && result <= 9223372036854775807)
        result_as_an_long = result;
    return (result_as_an_long);
}

long my_getnbr(char const *str)
{
    long i = 0;
    long long result = 0;
    long pos_or_neg = 1;

    while (str[i] < '0' || (str[i] > '9' && str[i] != '\0'))
        i++;
    while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0') {
        if (str[i - 1] == '-')
            pos_or_neg = -1;
        result = result + str[i] - 48;
        if (str[i + 1] >= '0' && '9' >= str[i + 1] && str[i + 1] != '\0')
            result = result * 10;
        i++;
    }
    return (check_result_is_long(result * pos_or_neg));
}

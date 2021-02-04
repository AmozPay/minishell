/*
** EPITECH PROJECT, 2020
** my compute power rec by Amoz PAY
** File description:
** returns a number nb to the power of p
*/

int my_compute_power_rec(int nb, int p)
{
    int result_int;
    long long result = nb;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    if (p == 1)
        return (nb);
    result = result * my_compute_power_rec(nb, p - 1);
    if (result > 2147483647 || result < -2147483648)
        return (0);
    result_int = result;
    return (result_int);
}

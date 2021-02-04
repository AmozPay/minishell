/*
** EPITECH PROJECT, 2020
** my find prime sup by Amoz PAY
** File description:
** finds the smallest prime number above or equal to nb
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    if (nb < 2) {
        return (2);
    }
    while (my_is_prime(nb) != 1)
        nb++;
    return (nb);
}

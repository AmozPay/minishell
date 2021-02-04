/*
** EPITECH PROJECT, 2020
** my is prime by Amoz PAY
** File description:
** finds out if the int is is a prime number or not
*/

int my_is_prime(int nb)
{
    if (nb <=1)
        return (0);
    for (int i = 2; i <= nb/2 && i < 46342; i++) {
        if (nb % i == 0)
            return (0);
    }
    return (1);
}

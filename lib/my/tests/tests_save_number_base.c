/*
** EPITECH PROJECT, 2020
** save_nbr_base - Amoz Pay
** File description:
** Convert it into hex, oct or binary nb string - Test
*/

#include "my.h"
#include "my_printf.h"
#include <criterion/criterion.h>

Test(my_save_nbr_base, binary_conversions)
{
    cr_expect_str_eq(my_save_nbr_base(0, 2), "0");
    cr_expect_str_eq(my_save_nbr_base(1, 2), "1");
    cr_expect_str_eq(my_save_nbr_base(2, 2), "10");
    cr_expect_str_eq(my_save_nbr_base(3, 2), "11");
    cr_expect_str_eq(my_save_nbr_base(32, 2), "100000");
    cr_expect_str_eq(my_save_nbr_base(255, 2), "11111111");
    cr_expect_str_eq(my_save_nbr_base(1023, 2), "1111111111");
    cr_expect_str_eq(my_save_nbr_base(1023000, 2), "11111001110000011000");
}

Test(my_save_nbr_base, octal_conversions)
{
    cr_expect_str_eq(my_save_nbr_base(0, 8), "0");
    cr_expect_str_eq(my_save_nbr_base(1, 8), "1");
    cr_expect_str_eq(my_save_nbr_base(2, 8), "2");
    cr_expect_str_eq(my_save_nbr_base(3, 8), "3");
    cr_expect_str_eq(my_save_nbr_base(32, 8), "40");
    cr_expect_str_eq(my_save_nbr_base(255, 8), "377");
    cr_expect_str_eq(my_save_nbr_base(1023, 8), "1777");
    cr_expect_str_eq(my_save_nbr_base(1023000, 8), "3716030");
    cr_expect_str_eq(my_save_nbr_base(9999999999, 8), "112402761777");
}

Test(my_save_nbr_base, hexadecimal_conversions)
{
    cr_expect_str_eq(my_save_nbr_base(0, 16), "0");
    cr_expect_str_eq(my_save_nbr_base(1, 16), "1");
    cr_expect_str_eq(my_save_nbr_base(2, 16), "2");
    cr_expect_str_eq(my_save_nbr_base(3, 16), "3");
    cr_expect_str_eq(my_save_nbr_base(32, 16), "20");
    cr_expect_str_eq(my_save_nbr_base(255, 16), "ff");
    cr_expect_str_eq(my_save_nbr_base(1023, 16), "3ff");
    cr_expect_str_eq(my_save_nbr_base(1023000, 16), "f9c18");
    cr_expect_str_eq(my_save_nbr_base(9999999999, 16), "2540be3ff");
}

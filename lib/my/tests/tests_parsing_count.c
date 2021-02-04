/*
** EPITECH PROJECT, 2020
** my_printf - Amoz PAY
** File description:
** test section for parsing count
*/

#include <criterion/criterion.h>
#include "my_printf.h"

Test(parsing_count, test_1)
{
    cr_expect_eq(parsing_count("abcde%%"), 2);
    cr_expect_eq(parsing_count("abcde%0d"), 2);
    cr_expect_eq(parsing_count("abcde%+5"), 1);
    cr_expect_eq(parsing_count("abcde%0"), 1);
    cr_expect_eq(parsing_count("abcde%50.5x"), 2);
    cr_expect_eq(parsing_count("abcde%50.5xx"), 3);
    cr_expect_eq(parsing_count("abcde%50.5xx"), 3);
    cr_expect_eq(parsing_count("abcde%%wezeg%o"), 4);
}

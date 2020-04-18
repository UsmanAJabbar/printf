#include <limits.h>
#include <stdio.h>
#include "holberton.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("_Let's try to printf a simple sentence.\n");
    len2 = printf(" Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("_Length:[%d, %i]\n", len, len);
    printf(" Length:[%d, %i]\n", len2, len2);
    _printf("_Negative:[%d]\n", -762534);
    printf(" Negative:[%d]\n", -762534);
    _printf("_Unsigned:[%u]\n", ui);
    printf(" Unsigned:[%u]\n", ui);
    _printf("_Unsigned octal:[%o]\n", ui);
    printf(" Unsigned octal:[%o]\n", ui);
    _printf("_Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf(" Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("_Character:[%c]\n", 'H');
    printf(" Character:[%c]\n", 'H');
    _printf("_String:[%s]\n", "I am a string !");
    printf(" String:[%s]\n", "I am a string !");
    _printf("_Address:[%p]\n", addr);
    printf(" Address:[%p]\n", addr);
    len = _printf("_Percent:[%%]\n");
    len2 = printf(" Percent:[%%]\n");
    _printf("_Len:[%d]\n", len);
    printf(" Len:[%d]\n", len2);
    _printf("_Unknown:[%P]\n");
    printf(" Unknown:[%P]\n");
    return (0);
}
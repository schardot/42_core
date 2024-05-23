#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include "printf.h"

int main()
{
	int ret[2];

	// Cas de base
	ret[0] = ft_printf("ft_printf: %s %d %x$\n", "hello", 42, 0x42);
	ret[1] = printf("___printf: %s %d %x$\n", "hello", 42, 0x42);
	if (ret[0] != ret[1])
		printf("Difference found: ret[0]=%d ret[1]=%d\n", ret[0], ret[1]);

	// Chaîne NULL
	ret[0] = ft_printf("ft_printf: %s\n", NULL);
	// ret[1] = printf("___printf: %s\n", NULL);
	if (ret[0] != ret[1])
		printf("Difference found: ret[0]=%d ret[1]=%d\n", ret[0], ret[1]);

	// Entier négatif
	ret[0] = ft_printf("ft_printf: %d\n", INT_MIN);
	ret[1] = printf("___printf: %d\n", INT_MIN);
	if (ret[0] != ret[1])
		printf("Difference found: ret[0]=%d ret[1]=%d\n", ret[0], ret[1]);

	// Grand nombre hexadécimal
	ret[0] = ft_printf("ft_printf: %x\n", 0x7FFFFFFF);
	ret[1] = printf("___printf: %x\n", 0x7FFFFFFF);
	if (ret[0] != ret[1])
		printf("Difference found: ret[0]=%d ret[1]=%d\n", ret[0], ret[1]);

	// Caractères spéciaux
	ret[0] = ft_printf("ft_printf: %s\n", "!@#$%^&*()");
	ret[1] = printf("___printf: %s\n", "!@#$%^&*()");
	if (ret[0] != ret[1])
		printf("Difference found: ret[0]=%d ret[1]=%d\n", ret[0], ret[1]);

	// Longue chaîne
	ret[0] = ft_printf("ft_printf: %s\n", "This is a very long string to test the functionality of the ft_printf function in different scenarios.");
	ret[1] = printf("___printf: %s\n", "This is a very long string to test the functionality of the ft_printf function in different scenarios.");
	if (ret[0] != ret[1])
		printf("Difference found: ret[0]=%d ret[1]=%d\n", ret[0], ret[1]);

	// Plusieurs spécificateurs de format
	ret[0] = ft_printf("ft_printf: %d %s %x\n", 123, "abc", 0xABC);
	ret[1] = printf("___printf: %d %s %x\n", 123, "abc", 0xABC);
	if (ret[0] != ret[1])
		printf("Difference found: ret[0]=%d ret[1]=%d\n", ret[0], ret[1]);

	// Test avec le plus grand entier 'int'
	ret[0] = ft_printf("ft_printf: %d\n", INT_MAX);
	ret[1] = printf("___printf: %d\n", INT_MAX);
	if (ret[0] != ret[1])
		printf("Difference found: ret[0]=%d ret[1]=%d\n", ret[0], ret[1]);

	// Test avec le plus petit entier 'int'
	ret[0] = ft_printf("ft_printf: %d\n", INT_MIN);
	ret[1] = printf("___printf: %d\n", INT_MIN);
	if (ret[0] != ret[1])
		printf("Difference found: ret[0]=%d ret[1]=%d\n", ret[0], ret[1]);

	// Test avec INT_MAX + 1
	//ret[0] = ft_printf("ft_printf: %d\n", INT_MAX + 1);
	//ret[1] = printf("___printf: %d\n", INT_MAX + 1);
	// if (ret[0] != ret[1])
	// 	printf("Difference found: ret[0]=%d ret[1]=%d\n", ret[0], ret[1]);

	// Test avec INT_MIN - 1
	// ret[0] = ft_printf("ft_printf: %d\n", INT_MIN - 1);
	// ret[1] = printf("___printf: %d\n", INT_MIN - 1);
	// if (ret[0] != ret[1])
	// 	printf("Difference found: ret[0]=%d ret[1]=%d\n", ret[0], ret[1]);

	// Test avec INT_MAX en hexadécimal
	ret[0] = ft_printf("ft_printf: %x\n", INT_MAX);
	ret[1] = printf("___printf: %x\n", INT_MAX);
	if (ret[0] != ret[1])
		printf("Difference found: ret[0]=%d ret[1]=%d\n", ret[0],ret[1]);

	// Test avec INT_MIN en hexadécimal
	ret[0] = ft_printf("ft_printf: %x\n", INT_MIN);
	ret[1] = printf("___printf: %x\n", INT_MIN);
	if (ret[0] != ret[1])
		printf("Difference found: ret[0]=%d ret[1]=%d\n",ret[0], ret[1]);

	// Test avec INT_MAX + 1 en hexadécimal
	// ret[0] = ft_printf("ft_printf: %x\n", INT_MAX + 1);
	// ret[1] = printf("___printf: %x\n", INT_MAX + 1);
	// if (ret[0] != ret[1])
	// 	printf("Difference found: ret[0]=%d ret[1]=%d\n",ret[0], ret[1]);

	// Test avec INT_MIN - 1 en hexadécimal
	// ret[0] = ft_printf("ft_printf: %x\n", INT_MIN - 1);
	// ret[1] = printf("___printf: %x\n", INT_MIN - 1);
	// if (ret[0] != ret[1])
	// 	printf("Difference found: ret[0]=%d ret[1]=%d\n",ret[0], ret[1]);

	// Test avec nb = base (10 et 16)
	ret[0] = ft_printf("ft_printf: %d %x\n", 10, 16);
	ret[1] = printf("___printf: %d %x\n", 10, 16);
	if (ret[0] != ret[1])
		printf("Difference found: ret[0]=%d ret[1]=%d\n",ret[0], ret[1]);

	// Test avec nb = base + 1 (10 et 16)
	ret[0] = ft_printf("ft_printf: %d %x\n", 11, 17);
	ret[1] = printf("___printf: %d %x\n", 11, 17);
	if (ret[0] != ret[1])
		printf("Difference found: ret[0]=%d ret[1]=%d\n",ret[0], ret[1]);

	// Test avec nb = base - 1 (10 et 16)
	ret[0] = ft_printf("ft_printf: %d %x\n", 9, 15);
	ret[1] = printf("___printf: %d %x\n", 9, 15);
	if (ret[0] != ret[1])
		printf("Difference found: ret[0]=%d ret[1]=%d\n",ret[0], ret[1]);

	// Test avec nb = -base (10 et 16)
	ret[0] = ft_printf("ft_printf: %d %x\n", -10, -16);
	ret[1] = printf("___printf: %d %x\n", -10, -16);
	if (ret[0] != ret[1])
		printf("Difference found: ret[0]=%d ret[1]=%d\n",ret[0], ret[1]);

	// Test avec nb = -base (10 et 16)
	ret[0] = ft_printf("ft_printf: %d %x\n", -11, -17);
	ret[1] = printf("___printf: %d %x\n", -11, -17);
	if (ret[0] != ret[1])
		printf("Difference found: ret[0]=%d ret[1]=%d\n",ret[0],ret[1]);

	// Test avec nb = -base + 1 (10 et 16)
	ret[0] = ft_printf("ft_printf: %d %x\n", -9, -15);
	ret[1] = printf("___printf: %d %x\n", -9, -15);
	if (ret[0] != ret[1])
		printf("Difference found: ret[0]=%d ret[1]=%d\n",ret[0],ret[1]);

	// Test avec un grand nombre hexadécimal (lettres majuscules)
	ret[0] = ft_printf("ft_printf: %x\n", 0xDEADBEEF);
	ret[1] = printf("___printf: %x\n", 0xDEADBEEF);
	if (ret[0] != ret[1])
		printf("Difference found: ret[0]=%d ret[1]=%d\n", ret[0], ret[1]);

	// Test avec une chaîne contenant des caractères d'échappement
	ret[0] = ft_printf("ft_printf: Hello\nWorld\tTab\n");
	ret[1] = printf("___printf: Hello\nWorld\tTab\n");
	if (ret[0] != ret[1])
		printf("Difference found: ret[0]=%d ret[1]=%d\n", ret[0], ret[1]);

	// Test avec une chaîne sans spécificateur de format
	ret[0] = ft_printf("ft_printf: Just a simple text without format specifiers\n");
	ret[1] = printf("___printf: Just a simple text without format specifiers\n");
	if (ret[0] != ret[1])
		printf("Difference found: ret[0]=%d ret[1]=%d\n", ret[0], ret[1]);

		// Test avec des spécificateurs de format consécutifs
	ret[0] = ft_printf("ft_printf: %s%d%x\n", "Text", 123, 0xABC);
    ret[1] = printf("___printf: %s%d%x\n", "Text", 123, 0xABC);
    if (ret[0] != ret[1])
        printf("Difference found: ret[0]=%d ret[1]=%d\n", ret[0], ret[1]);
}

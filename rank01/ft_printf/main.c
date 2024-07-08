#include "ft_printf.h"

#include <stdio.h>
#include <limits.h>

int main(void)
{
    int     d = 42;
    char    c = 'a';
    unsigned int u = UINT_MAX;

    //SIMPLE TESTS

    ft_printf("\033[44mSimple Tests\033[0m\n- Check that the usual conversions %%s, %%p et %%d work fine\n\n\033[45m%%s test - \"string\"\033[0m\n");
    //%s test
    ft_printf("ft_printf: ");
    ft_printf("\nBytes written: \033[0;36m%d\033[0m\n", ft_printf("%s", "string"));
    ft_printf("printf: ");
    printf("\nBytes written: \033[0;36m%d\033[0m\n", printf("%s", "string"));
    
    //%d test
    ft_printf("\n\033[45m%%d test - \"42\"\033[0m\n");
    ft_printf("ft_printf: ");
    ft_printf("\nBytes written: \033[0;36m%d\033[0m\n", ft_printf("%d", d));
    ft_printf("printf: ");
    printf("\nBytes written: \033[0;36m%d\033[0m\n", printf("%d", d));

    //%p test
    ft_printf("\n\033[45m%%p test\033[0m\n");
    ft_printf("ft_printf: ");
    ft_printf("\nBytes written: \033[0;36m%d\033[0m\n", ft_printf("%p", &d));
    ft_printf("printf: ");
    printf("\nBytes written: \033[0;36m%d\033[0m\n", printf("%p", &d));

    //%% test
    ft_printf("\n\033[45m%%%% test\033[0m\n\n");
    ft_printf("ft_printf: ");
    ft_printf("\nBytes written: \033[0;36m%d\033[0m\n", ft_printf("%%"));
    ft_printf("printf: ");
    printf("\nBytes written: \033[0;36m%d\033[0m\n", printf("%%"));

    // ft_printf("Less simple Tests\nCheck that you can put multiple conversions (and so multiple arguments) of the same type in a same printf.\n");
    // ft_printf("%%s test\n");
    // ft = ft_printf("%s and %s and %s %s", s, s, s, s);
    // ft_printf("\nBytes written: %d\n", ft);
    // ft_printf("printf:\n");
    // og = printf("%s and %s and %s %s", s, s, s, s);
    // printf("\nBytes written: %d\n", og);

    // ft_printf("%%d test\n");
    // ft = ft_printf("%d and %d and %d %d", d, d, d, d);
    // ft_printf("\nBytes written: %d\n", ft);
    // ft_printf("printf:\n");
    // og = printf("%d and %d and %d %d", d, d, d, d);
    // printf("\nBytes written: %d\n", og);

    // ft_printf("%%p test\n");
    // ft = ft_printf("%p and %p and %p %p", &d, &d, &c, &d);
    // ft_printf("\nBytes written: %d\n", ft);
    // ft_printf("printf:\n");
    // og = printf("%p and %p and %p %p", &d, &d, &c, &d);
    // printf("\nBytes written: %d\n", og);

    // ft_printf("%%c test\n");
    // ft = ft_printf("%c and %c and %c %c", c, c, 'b', c);
    // ft_printf("\nBytes written: %d\n", ft);
    // ft_printf("printf:\n");
    // og = printf("%c and %c and %c %c", c, c, 'b', c);
    // printf("\nBytes written: %d\n", og);

    //SLIGHTLY COMPLICATED TESTS

    ft_printf("\033[44mSlightly complicated tests\033[0m\nCheck that the less usual conversions %i, %u, %x, %X and %c work fine while doing multiple calls\n");
    //%i test
    ft_printf("\n\033[45m%%i test - \"42\"\033[0m\n");
    ft_printf("ft_printf: ");
    ft_printf("\nBytes written: \033[0;36m%d\033[0m\n", ft_printf("%i and %i and %i %i", d, d, d, d));
    ft_printf("printf: ");
    printf("\nBytes written: \033[0;36m%d\033[0m\n", printf("%i and %i and %i %i", d, d, d, d));

    //%u test
    ft_printf("\n\033[45m%%u test - \"4294967295 which is UINTMAX\"\033[0m\n");
    ft_printf("ft_printf: ");
    ft_printf("\nBytes written: \033[0;36m%d\033[0m\n", ft_printf("%u and %u and %u %u", u, u, u, u));
    ft_printf("printf: ");
    printf("\nBytes written: \033[0;36m%d\033[0m\n", printf("%u and %u and %u %u", u, u, u, u));

    //%x test
    ft_printf("\n\033[45m%%x test - \"2147483646 turns into 7ffffffe\"\033[0m\n");
    ft_printf("ft_printf: ");
    ft_printf("\nBytes written: \033[0;36m%d\033[0m\n", ft_printf("%x and %x and %x %x", u, u, u, u));
    ft_printf("printf: ");
    printf("\nBytes written: \033[0;36m%d\033[0m\n", printf("%x and %x and %x %x", u, u, u, u));

    //%X test
    ft_printf("\n\033[45m%%x test - \"2147483646 turns into 7FFFFFFE\"\033[0m\n");
    ft_printf("ft_printf: ");
    ft_printf("\nBytes written: \033[0;36m%d\033[0m\n", ft_printf("%X and %X and %X %X", u, u, u, u));
    ft_printf("printf: ");
    printf("\nBytes written: \033[0;36m%d\033[0m\n", printf("%X and %X and %X %X", u, u, u, u));

    //%c test
    ft_printf("\n\033[45m%%c test - \"a\"\033[0m\n");
    ft_printf("ft_printf: ");
    ft_printf("\nBytes written: \033[0;36m%d\033[0m\n", ft_printf("%c and %c and %c %c", c, c, c, c));
    ft_printf("printf: ");
    ft_printf("\nBytes written: \033[0;36m%d\033[0m\n", printf("%c and %c and %c %c", c, c, c, c));

}
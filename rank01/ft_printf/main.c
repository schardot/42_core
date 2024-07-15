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
    ft_printf("\n\033[45m%%x test - \"2147483646 turns into ffffffff\"\033[0m\n");
    ft_printf("ft_printf: ");
    ft_printf("\nBytes written: \033[0;36m%d\033[0m\n", ft_printf("%x and %x and %x %x", u, u, u, u));
    ft_printf("printf: ");
    printf("\nBytes written: \033[0;36m%d\033[0m\n", printf("%x and %x and %x %x", u, u, u, u));

    //%X test
    ft_printf("\n\033[45m%%x test - \"2147483646 turns into FFFFFFFF\"\033[0m\n");
    ft_printf("ft_printf: ");
    ft_printf("\nBytes written: \033[0;36m%d\033[0m\n", ft_printf("%X and %X and %X %X", u, u, u, u));
    ft_printf("printf: ");
    printf("\nBytes written: \033[0;36m%d\033[0m\n", printf("%X and %X and %X %X", u, u, u, u));

    //%c test
    ft_printf("\n\033[45m%%c test - \"a\"\033[0m\n");
    ft_printf("ft_printf: ");
    ft_printf("\nBytes written: \033[0;36m%d\033[0m\n", ft_printf("%c and %c and %c %c", c, c, c, c));
    ft_printf("printf: ");
    printf("\nBytes written: \033[0;36m%d\033[0m\n", printf("%c and %c and %c %c", c, c, c, c));

    //0 test
    ft_printf("\n\033[45m0 test - should return -1\033[0m\n");
    ft_printf("ft_printf: ");
    ft_printf("\nBytes written: \033[0;36m%d\033[0m\n", ft_printf(0));
    ft_printf("printf: ");
    ft_printf("\nBytes written: \033[0;36m%d\033[0m\n", printf(0));

    //empty string test
    ft_printf("\n\033[45m""/empty string test - should do nothing\033[0m\n");
    ft_printf("ft_printf: ");
    ft_printf("\nBytes written: \033[0;36m%d\033[0m\n", ft_printf("%s",""));
    ft_printf("printf: ");
    ft_printf("\nBytes written: \033[0;36m%d\033[0m\n", printf("%s",""));

    //INT_MIN test
    ft_printf("\n\033[45m""smallest int test - \033[0m\n");
    ft_printf("ft_printf: ");
    ft_printf("\nBytes written: \033[0;36m%d\033[0m\n", ft_printf("%d",INT_MIN));
    ft_printf("printf: ");
    ft_printf("\nBytes written: \033[0;36m%d\033[0m\n", printf("%d",INT_MIN));
    
    //NULL test
    ft_printf("\n\033[45m""NULL pointer test - ""-2147483648"" \033[0m\n");
    ft_printf("ft_printf: ");
    ft_printf("\nBytes written: \033[0;36m%d\033[0m\n", ft_printf("%p", NULL));
    ft_printf("printf: ");
    ft_printf("\nBytes written: \033[0;36m%d\033[0m\n", printf("%p", NULL));
}

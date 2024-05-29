# MANDATORY PART

 ## Program name: 🟡 libftprintf.a

 Passed moulinette? 🔴 - haven't tried yet

 Turn in files: 🟡 Makefile, 🟡 *.h, 🟡 */*.h, 🟡 *.c, , 🟡 */*.c

 Makefile: NAME, all, clean, fclean, re

 External functs. malloc, free, write, va_start, va_arg, va_copy, va_end

 Libft authorized: Yes

Description: Write a library that contains ft_printf(), a function that will mimic the original printf()

### The funcion has to handle the following conversions: cspdiuxX%

| Conversion | Description | Format function | Written | Manually tested | Norminetted | Final check | Francinetted |
| --------- | ------ | --- | ------- | ------ | ----------- | ----------- | ----------- |
| %c | Prints a single character. | ft_printchar | :green_circle: | :red_circle: | :red_circle: | :red_circle: | :red_circle: |
| %s | Prints a string (as defined by the common C convention). | ft_printstr | :green_circle: | :red_circle: | :red_circle: | :red_circle: | :red_circle: |
| %p | The void * pointer argument has to be printed in hexadecimal format. | ft_putaddr | :green_circle: | :red_circle: | :red_circle: | :red_circle: | :red_circle: |
| %d | Prints a decimal (base 10) number. | ft_printnbr | :green_circle: | :red_circle: | :red_circle: | :red_circle: | :red_circle: |
| %i | Prints an integer in base 10. | ft_printnbr | :green_circle: | :red_circle: | :red_circle: | :red_circle: | :red_circle: |
| %u | Prints an unsigned decimal number. | 🔴 | 🔴 | :red_circle: | :red_circle: | :red_circle: | :red_circle: |
| %x | Prints a number in hexadecimal lowercase format. | ft_putnbr_base | :green_circle: | :red_circle: | :red_circle: | :red_circle: | :red_circle: |
| %X | Prints a number in hexadecimal uppercase format. | ft_putnbr_base | :green_circle: | :red_circle: | :red_circle: | :red_circle: | :red_circle: |
| %% | Prints a percent sign. | ft_printchar | :green_circle: | :red_circle: | :red_circle: | :red_circle: | :red_circle: |


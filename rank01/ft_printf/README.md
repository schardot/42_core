# ft_printf 🖨️

`ft_printf` is a reimplementation of the standard C library function `printf`. This project demonstrates the ability to handle formatted output, managing different format specifiers, and producing customized output with variable arguments.

## 🔧 Project Overview

- **Handle various format specifiers** such as `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, and `%X`.
- **Utilize variadic functions** in C to handle a variable number of arguments.

## 📑 Features

- **Format Specifiers**: Conversion specifiers for printing characters, strings, pointers, integers, and hexadecimals.

# Overview of `ft_printf.c`

## Function: `ft_printf`
The `ft_printf` function is the entry point for your custom formatted output function. It mimics the behavior of the standard `printf`.

- **Parameters**:
  - `const char *s`: The format string containing format specifiers.
  - `...`: A variable list of arguments to be formatted.

- **Functionality**:
  - Initializes a `va_list` to access the variable arguments.
  - Checks for a null format string, returning `-1` if so.
  - Iterates through each character of the format string:
    - If a `%` is encountered followed by a valid format specifier (checked using `ft_strchr`), it calls `ft_format` to handle that specifier and accumulates the length of the output.
    - If the character is not a format specifier, it prints the character using `ft_printchar` and increments the length.
  - Returns the total length of the output.

## Function: `ft_format`
The `ft_format` function processes individual format specifiers.

- **Parameters**:
  - `int c`: The format specifier character.
  - `va_list *args`: The list of arguments.

- **Functionality**:
  - Uses a series of conditional statements to determine which format specifier is present:
    - Calls appropriate functions (`ft_printchar`, `ft_printstr`, `ft_printaddr`, `ft_printnbr`, `ft_printnbr_unsigned`, and `ft_putnbr_base`) to format and print the corresponding argument.
    - Accumulates the length of the formatted output and returns it.

## Function: `ft_strchr`
The `ft_strchr` function is a utility that searches for the first occurrence of a character in a string.

- **Parameters**:
  - `const char *s`: The string to be searched.
  - `int c`: The character to search for.

- **Functionality**:
  - Iterates through the string and returns a pointer to the first occurrence of the character, or `NULL` if the character is not found.

## Function: `ft_strlen`
The `ft_strlen` function calculates the length of a given string.

- **Parameters**:
  - `const char *s`: The string whose length is to be calculated.

- **Functionality**:
  - Iterates through the string until the null terminator is reached, counting the characters and returning the total length.

# Overview of `format_diuxX.c`

## Function: `ft_printnbr`
The `ft_printnbr` function is responsible for printing signed integers.

- **Parameters**:
  - `int nb`: The integer value to be printed.

- **Functionality**:
  - Initializes a length counter (`len`) to zero.
  - Handles the special case for `INT_MIN`, printing it directly as a string since its absolute value exceeds the range of `int`.
  - If the number is negative, it converts it to positive and prints a negative sign.
  - Uses recursion to print each digit:
    - If the number is less than 10, it prints the digit directly.
    - For larger numbers, it recursively calls itself to print each digit by dividing the number by 10.

## Function: `ft_printnbr_unsigned`
The `ft_printnbr_unsigned` function handles the printing of unsigned integers.

- **Parameters**:
  - `unsigned int nb`: The unsigned integer value to be printed.

- **Functionality**:
  - Similar to `ft_printnbr`, but it does not handle negative values.
  - Uses recursion to print the digits, accumulating the length of the output as it goes.

## Function: `ft_putnbr_base`
The `ft_putnbr_base` function converts an unsigned integer to a specified base and prints it.

- **Parameters**:
  - `unsigned int nbr`: The number to be converted.
  - `const char *base`: A string representing the base characters (e.g., "0123456789abcdef" for hexadecimal).

- **Functionality**:
  - Determines the length of the base using `ft_strlen`.
  - Uses recursion to convert and print the number:
    - If the number is less than the base length, it prints the corresponding character from the base string.
    - For larger numbers, it recursively divides the number by the base length to process each digit.



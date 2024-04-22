#include "libft.h"

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    char    *d = dest;
    const char    *s = src;
    while (n > 0)
    {
        *d++ = *s++;
        n --;
    }
    return (dest);
}

// #include <stdio.h>

// int main(void)
// {
//     char dest[] = "Hello";
//     char src[] = "abc";

//     printf("Before memcpy, dest: %s\n", dest);
//     printf("After memcpy, dest: %s\n", (char *)ft_memcpy(dest, src, ft_strlen(dest)));
// }

// In C, when dealing with pointers and memory manipulation functions like memcpy, it 's essential to handle the types correctly to avoid potential issues related to pointer arithmetic and type safety. Let' s delve into why using separate pointers d and s is necessary :

//     Type Safety : The original arrays dest and src are of type void *and const void *,
//                   respectively.These types are generic pointers and don't provide information about the size or type of the data they point to. Thus, directly using them for pointer arithmetic could lead to incorrect behavior or compiler warnings/errors. Pointer Arithmetic : Pointer arithmetic is based on the size of the data type being pointed to.When you increment a pointer,
//                   it moves forward by the size of that data type.In the case of memcpy,
//                   you're copying byte-by-byte, so you need to increment pointers by one byte at a time. Using char * pointers ensures that incrementing them moves to the next byte correctly, irrespective of the data type they point to. const Qualifier:
// The const qualifier is used for src because memcpy should not modify the data pointed to by src. By declaring s as const char *, you ensure that the function doesn't accidentally modify the source data.
// By using separate pointers d and s, you maintain type safety, ensure correct pointer arithmetic, and respect the const qualifier for src. This approach ensures that your code is clear, correct, and robust, making it easier to understand and maintain.
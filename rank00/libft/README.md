[![Libft bonus badge](https://github.com/ayogun/42-project-badges/blob/main/badges/libftm.png?raw=true)](https://github.com/schardot/42_core/tree/main/rank00/libft)

# Libft - ![Static Badge](https://img.shields.io/badge/moulinette-125%25-brightgreen?style=flat-square)

Libft is a custom C library that reimplements essential functions from the standard C library, as well as additional utility functions to assist with string manipulation, memory management, and linked list operations. This project serves as the foundation for many future projects at 42.

## 📁 Project Overview
The libft library is divided into three main sections:

**Libc functions:** Reimplementations of functions like memset, strlen, strdup, etc.

**Additional functions:** Utility functions for string manipulation, memory allocation, and linked list handling.

**Bonus part:** Functions to manipulate linked lists.

## 🛠️ Functions Implemented

### 🧠 Memory Functions

- [ft_memset](./src/ft_memset.c): Fills a block of memory with a specific byte value.
- [ft_bzero](./src/ft_bzero.c): Sets a block of memory to zero.
- [ft_memcpy](./src/ft_memcpy.c): Copies memory from one location to another.
- [ft_memmove](./src/ft_memmove.c): Safely copies overlapping memory blocks.
- [ft_memchr](./src/ft_memchr.c): Searches for a specific byte in a memory block.
- [ft_memcmp](./src/ft_memcmp.c): Compares two memory blocks byte by byte.

### ✂️ String Manipulation

- [ft_strlen](./src/ft_strlen.c): Returns the length of a string.
- [ft_strdup](./src/ft_strdup.c): Duplicates a string by allocating memory.
- [ft_strcpy](./src/ft_strcpy.c): Copies a string from source to destination.
- [ft_strjoin](./src/ft_strjoin.c): Concatenates two strings into one.
- [ft_strtrim](./src/ft_strtrim.c): Removes leading and trailing characters from a string.
- [ft_split](./src/ft_split.c): Splits a string into an array using a delimiter.
- [ft_substr](./src/ft_substr.c): Extracts a substring from a given string.
  
### 🔢 Character & Number Conversion

- [ft_atoi](./src/ft_atoi.c): Converts a string to an integer.
- [ft_itoa](./src/ft_itoa.c): Converts an integer to a string.
- [ft_isalpha](./src/ft_isalpha.c): Checks if a character is alphabetic.
- [ft_isdigit](./src/ft_isdigit.c): Checks if a character is a digit.
- [ft_isalnum](./src/ft_isalnum.c): Checks if a character is alphanumeric.
- [ft_isascii](./src/ft_isascii.c): Checks if a character is within the ASCII set.
- [ft_isprint](./src/ft_isprint.c): Checks if a character is printable.
  
### 🔗 Linked List Functions

- [ft_lstnew](./src/ft_lstnew.c): Creates a new linked list node.
- [ft_lstadd_front](./src/ft_lstadd_front.c): Adds a node to the front of a list.
- [ft_lstsize](./src/ft_lstsize.c): Returns the size of a list.
- [ft_lstlast](./src/ft_lstlast.c): Returns the last node in a list.
- [ft_lstdelone](./src/ft_lstdelone.c): Deletes a node from a list.
- [ft_lstclear](./src/ft_lstclear.c): Deletes all nodes in a list.
- [ft_lstiter](./src/ft_lstiter.c): Applies a function to each node in a list.

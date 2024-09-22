# Libft

Libft is a custom C library that reimplements essential functions from the standard C library, as well as additional utility functions to assist with string manipulation, memory management, and linked list operations. This project serves as the foundation for many future projects at 42.

## 📁 Project Overview
The libft library is divided into three main sections:

**Libc functions:** Reimplementations of functions like memset, strlen, strdup, etc.
**Additional functions:** Utility functions for string manipulation, memory allocation, and linked list handling.
**Bonus part:** Functions to manipulate linked lists.

## 🛠️ Functions Implemented

### 🧠 Memory Functions

- ft_memset: Fills a block of memory with a specific byte value.
- ft_bzero: Sets a block of memory to zero.
- ft_memcpy: Copies memory from one location to another.
- ft_memmove: Safely copies overlapping memory blocks.
- ft_memchr: Searches for a specific byte in a memory block.
- ft_memcmp: Compares two memory blocks byte by byte.

### ✂️ String Manipulation

- ft_strlen: Returns the length of a string.
- ft_strdup: Duplicates a string by allocating memory.
- ft_strcpy: Copies a string from source to destination.
- ft_strjoin: Concatenates two strings into one.
- ft_strtrim: Removes leading and trailing characters from a string.
- ft_split: Splits a string into an array using a delimiter.
- ft_substr: Extracts a substring from a given string.
  
### 🔢 Character & Number Conversion

- ft_atoi: Converts a string to an integer.
- ft_itoa: Converts an integer to a string.
- ft_isalpha: Checks if a character is alphabetic.
- ft_isdigit: Checks if a character is a digit.
- ft_isalnum: Checks if a character is alphanumeric.
- ft_isascii: Checks if a character is within the ASCII set.
- ft_isprint: Checks if a character is printable.
  
### 🔗 Linked List Functions

- ft_lstnew: Creates a new linked list node.
- ft_lstadd_front: Adds a node to the front of a list.
- ft_lstsize: Returns the size of a list.
- ft_lstlast: Returns the last node in a list.
- ft_lstdelone: Deletes a node from a list.
- ft_lstclear: Deletes all nodes in a list.
- ft_lstiter: Applies a function to each node in a list.

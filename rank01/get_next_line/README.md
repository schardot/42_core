# get_next_line ![Static Badge](https://img.shields.io/badge/moulinette-105%25-brightgreen?style=flat-square)

`get_next_line` is a C function designed to read a line from a file descriptor, allowing for efficient reading from both files and standard input. The function handles multiple calls and returns one line at a time, including the terminating newline character when applicable.

## Features

- Repeated calls to `get_next_line()` read from the specified file descriptor one line at a time.
- Returns the line read, or `NULL` if there's nothing left to read or an error occurs.
- Supports reading from both files and standard input.
- The returned line includes the terminating newline character, except when the end of the file is reached without a newline.
  
## Instructions

| Status | Description |
| --- | --- |
| :green_circle: | Repeated calls should read the text file pointed to by the file descriptor, one line at a time. |
| :green_circle: | Returns the line that was read, or `NULL` if no more data is available. |
| :green_circle: | Functions correctly for both file and standard input. |
| :green_circle: | Returned line includes a terminating newline character, unless at the end of the file. |
| :green_circle: | The header file `get_next_line.h` must contain the prototype of the `get_next_line()` function. |
| :green_circle: | Add all helper functions in `get_next_line_utils.c`. |
| :green_circle: | Use the option `-D BUFFER_SIZE=n` in the compiler call to define the buffer size for `read()`. |
| :green_circle: | Compile as follows (example with a buffer size of 42): `cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c` |
| :green_circle: | Undefined behavior occurs if the file descriptor changes between calls without reaching EOF. |
| :green_circle: | Undefined behavior may also occur when reading binary files. Logical handling is encouraged. |

## Installation

To use the `get_next_line` function, include the header file in your project:

```c
#include "get_next_line.h"


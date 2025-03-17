# **get_next_line**

A C function that reads a line from a file descriptor efficiently, returning one line at a time.

## 📜 Table of Contents
- [Features](#-features)
- [Usage](#-usage)
- [Compilation](#-compilation)
- [Project Requirements](#-project-requirements)
- [Notes on Behavior](#-notes-on-behavior)
- [License](#-license)

## 🚀 Features
✅ Reads one line at a time from a given file descriptor.

✅ Supports both file and standard input (`stdin`).

✅ Handles multiple calls efficiently, preserving state between reads.

✅ Returns `NULL` when EOF is reached or an error occurs.

✅ Includes the newline character (`\n`), except at the end of the file if there's no trailing newline.

✅ Configurable buffer size using `-D BUFFER_SIZE=n`.

## 📌 Usage

### **Basic Example: Reading from a File**
```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

### **Standard Input Example (Reading User Input)**
```c
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    char *line;

    printf("Enter text (Ctrl+D to stop):\n");
    while ((line = get_next_line(0)) != NULL)
    {
        printf("You entered: %s", line);
        free(line);
    }
    return 0;
}
```

## 🛠 Compilation  
You can specify a custom buffer size when compiling:    
```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```
If `BUFFER_SIZE` is **not defined**, the program defaults to a buffer size of **1**.

## 📋 Project Requirements  
- Must include `get_next_line.h` with function prototypes.  
- Helper functions should be in `get_next_line_utils.c`.  
- Function **must not leak memory** and should free dynamically allocated memory properly.  
- **If `BUFFER_SIZE` is not explicitly defined, it defaults to 1.**  
- Works with file descriptors and standard input.  

## ⚠️ Notes on Behavior
- **Changing file descriptors** between calls before reaching EOF may cause unexpected behavior.  
- **Binary files** are not explicitly supported but can be handled with modifications.  
- **Performance consideration:** A small `BUFFER_SIZE` (e.g., `1`) can impact performance, while a larger value may improve efficiency.  

## 📄 License  
This project is licensed under the [MIT License](LICENSE).  

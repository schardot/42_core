# MANDATORY PART

 ## Function name: :green_circle: get_next_line

 Passed moulinette? :green_circle:

 Turn in files: :green_circle: get_next_line.c, :green_circle: get_next_line_utils.c, :green_circle: get_next_line.h

 External functs. read, malloc, free

 Libft authorized: forbidden

Description: Write a function that returns a line read from a file descriptor

Instructions:


| Status | Description |
| --- | --- |
| :green_circle: | Repeated calls (e.g., using a loop) to your get_next_line() function should let you read the text file pointed to by the file descriptor, one line at a time. |
| :green_circle: | Your function should return the line that was read. If there is nothing else to read or if an error occurred, it should return NULL. |
| :green_circle: | Make sure that your function works as expected both when reading a file and when reading from the standard input. |
| :green_circle: | Please note that the returned line should include the terminating \n character, except if the end of file was reached and does not end with a \n character. |
| :green_circle: | Your header file get_next_line.h must at least contain the prototype of the get_next_line() function. |
| :green_circle: | Add all the helper functions you need in the get_next_line_utils.c file. |
| :green_circle: | Because you will have to read files in get_next_line(), add this option to your compiler call: -D BUFFER_SIZE=n. It will define the buffer size for read(). The buffer size value will be modified by your peer-evaluators and the Moulinette in order to test your code. |
| :green_circle: | You will compile your code as follows (a buffer size of 42 is used as an example): cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c |
| :green_circle: | We consider that get_next_line() has an undefined behavior if the file pointed toby the file descriptor changed since the last call whereas read() didn’t reach the end of file. |
| :green_circle: | We also consider that get_next_line() has an undefined behavior when readinga binary file. However, you can implement a logical way to handle this behavior if you want to. |

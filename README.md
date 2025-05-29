# Get_Next_Line

## Project Overview

**Get_Next_Line** is a project to write a function that returns a line read from a file descriptor. Repeated calls to this function allow reading a file (or input) line by line. The returned line includes the terminating newline character (`\n`), except when the end of the file is reached and it does not end with a newline.

---

## Function Prototype

```c
char *get_next_line(int fd);
```
---

## Description

- The function should allow repeated calls to read the file pointed to by `fd` one line at a time, returning the line read each call.
- It must work correctly when reading from both a file and standard input.
- The returned line should include the terminating newline character `\n`, except if the file does not end with one.
- Helper functions should be placed in `get_next_line_utils.c`.
- The compiler flag `-D BUFFER_SIZE=n` must be used to define the buffer size for `read()`.
- The function should be efficient, reading as little data as possible per call


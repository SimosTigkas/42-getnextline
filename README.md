# Project: Get_next_line

## Description
This project has to do with the function **char get_next_line(int fd);** which is returns a line  read from a
file descriptor!!

## Getting started

### Prerequisites

- C compiler (e.g., GCC)
- Standard C Library (stdlib.h)
- Unix Standard (unistd.h)
- File control (fcntl.h)

### Installation

Clone this repository:
```
   $ git clone git@github.com:SimosTigkas/42-getnextline.git
   $ cd 42-getnextline
```
### Usage
#include "get_next_line.h"
#include <fcntl.h> // Add this line for file control

int main(void) {
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    return (0);
}

### Configuration
**BUFFER_SIZE**: The size of the buffer for reading lines. Default is set to 24, but you can modify when you are compiling the program like this:
 ```
 gcc -Wall -Wextra -Werror -D BUFFER_SIZE=the_size_you_want_the_buffer_to_have get_next_line.c get_next_line_utils.c get_next_line.h main.c

```
### Frequently asked questions (FAQ)
**Q**: How does it handle large files?
**A**: The function reads the file line by line, avoiding the need to load the entire content into memory.

### Author
Simos Tigkas
LinkedIn: **https://www.linkedin.com/in/simos-tigkas-136394221/**

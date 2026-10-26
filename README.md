*This project has been created as part of the 42 curriculum by mbadarin.*

# GET_NEXT_LINE

## A 42 Amman Porject

### Description

A function that reads the first line of a file(s), and remembers the position of the last read line for subsequent calls.


### Instructions

Compile:
- get_next_line.c
- get_next_line_utils.c

using the following flags:
```
-Wall -Werror -Wextra
```
---
To compile object files:
```
cc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c -c
```
To compile object files with a custom *BUFFER_SIZE*:
```
cc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c -c -D BUFFER_SIZE=
```
To compile object files with a custom *MAX_FILES* -determine the maximum number of files for bonus part-:
```
cc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c -c -D MAX_FILES=
```
---
To call the function with a file discriptor (fd):
```
str = get_next_line(fd);
```

### Resources

- [OnlineGDB](https://www.onlinegdb.com/online_c_compiler)
- [The Open Group](https://pubs.opengroup.org/onlinepubs/007904875/functions/open.html)
- [GeeksforGeeks](https://www.geeksforgeeks.org/c/static-variables-in-c/)
- [Laboratoire d'informatique de l'École polytechnique](https://www.lix.polytechnique.fr/~liberti/public/computing/prog/c/C/FUNCTIONS/read.html)

#### Use of AI
Use of AI was limited, and mainly used with explicit prompts such as *"I am a new C learner, facing issue (X). Do not give answers. Act as a socratic tutor and ask questions that prod me in the reight direction."*  and for the purpose of generating test cases.

### Detailed desriptions

#### Mandatory

prototype:
```
char    get_next_line(int fd)
```
The function loops over the file and reads *BUFFER_SIZE* (default 4) bytes each time. It then parses the buffer until it encounters a newline character *-\n-*, runs out of bytes to read -*C's read returns 0*-, or encounters an error and fails to read -*C's read returns -1*-.

It then returns the read bytes as a string -*char \**-, and preserves any bytes that were read but not used in the buffer -*characters after a newline*-.

Subsequent calls return the next line in sequential order, in case the file still contains unread data, or *NULL* if it runs out of bytes or encounters an error.

#### Bonus

Functions identically to the mandatory function, but instead of handling one *fd*, it handles up to *MAX_FILES* (default 1024) files simultaneously.

The function tracks the read lines for each file separately, and can handle calls mixing different file descriptors at the same time.
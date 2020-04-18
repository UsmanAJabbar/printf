![alt text](https://www.geeksultd.com/wp-content/uploads/2020/03/printf.jpg "Logo")

# _printf
A Self-Made Printf Function By JI.Cruz and Usman Jabbar as a part of a Holberton School Curriculum.

## Requirements
- Linux (Recommended)
- gcc (>= 4.8.4)

## Files Required
- holberton.h
- _printf.c
- functions.c
- _putchar.c
- advanced_specifiers.c

| Files | Short Description |
| --- | --- |
| holberton.h | contains all prototypes |
| _printf.c | contains the all the main logic |
| functions.c | contains basic functions/format specifiers |
| _putchar.c | contains function to write to buffers |
| advanced_specifiers.c | contains all advanced format specifiers |

## Added Notes
This function makes major use of putchar in order to stay optimistic about memory since every single buffer requires a single block of memory.

## Install
On Linux, you could either download our program as a zip or simply clone our repository to your favourite folder.

### Instructions to clone our repository (Recommended)
``` Commands
sudo apt-get install git
cd /$YourFolder$/
git clone https://github.com/UsmanGTA/printf
```

### Using using the zip method
```
sudo apt-get install unzip
wget https://github.com/UsmanGTA/printf/archive/master.zip
cd /$YourFolder$/
unzip printf-master.zip
```

By cloning our github, you could make sure that you have all of the files necessary, along with a manpage highlighting the different formatting options available.

### Usage
After cloning our program, you could simply program your new program with our _printf function. Here's some of the usage examples.

```
#include holberton.h
.
.
.
```
```
_printf("This is an example of printing a %s", "string"); \\ Replaces %s with arguments
```
```
_printf("This is an example of printing a %d", "360); \\ Replaces %d with arguments
```
```
_printf("This is an example of printing a %i", "360); \\ Replaces %i with arguments
```
```
_printf("This is an example of printing a %r, "string"); \\ Replaces %r with reversed arguments
```
```
_printf("This is an example of printfing a %R, "string"); \\ Replaces %R with ROT13'ed string
```

## Built by
- Usman Abdul Jabbar Shaikh
- Jose Cruz Ruiz

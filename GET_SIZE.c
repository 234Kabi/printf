#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void print_binary(unsigned int num) {
    if (num > 1) {
        print_binary(num / 2);
    }
    putchar('0' + (num % 2));
}

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int chars_printed = 0;
    char buffer[BUFFER_SIZE];
    char *buf_ptr = buffer;

    const char *ptr = format;

    while (*ptr != '\0') {
        if (buf_ptr - buffer >= BUFFER_SIZE - 1) {
            // Buffer is full, write its content to stdout
            *buf_ptr = '\0';  // Null-terminate the buffer
            fputs(buffer, stdout);
            chars_printed += buf_ptr - buffer;
            buf_ptr = buffer;
        }

        if (*ptr == '%') {
            ptr++;  // Move past '%'
            
            if (*ptr == '\0') {
                // Reached end of format string
                break;
            }
            
            if (*ptr == 'c') {
                // Print a character
                char c = va_arg(args, int);
                *buf_ptr++ = c;
                chars_printed++;
            } else if (*ptr == 's') {
                // Print a string
                char *s = va_arg(args, char *);
                int len = strlen(s);
                strncpy(buf_ptr, s, BUFFER_SIZE - (buf_ptr - buffer) - 1);
                buf_ptr += len;
                chars_printed += len;
            } else if (*ptr == 'd' || *ptr == 'i') {
                // Print a signed integer
                int num = va_arg(args, int);
                int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%d", num);
                buf_ptr += len;
                chars_printed += len;
            } else if (*ptr == 'u') {
                // Print an unsigned integer in decimal format
                unsigned int num = va_arg(args, unsigned int);
                int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%u", num);
                buf_ptr += len;
                chars_printed += len;
            } else if (*ptr == 'o') {
                // Print an unsigned integer in octal format
                unsigned int num = va_arg(args, unsigned int);
                int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%o", num);
                buf_ptr += len;
                chars_printed += len;
            } else if (*ptr == 'x') {
                // Print an unsigned integer in lowercase hexadecimal format
                unsigned int num = va_arg(args, unsigned int);
                int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%x", num);
                buf_ptr += len;
                chars_printed += len;
            } else if (*ptr == 'X') {
                // Print an unsigned integer in uppercase hexadecimal format
                unsigned int num = va_arg(args, unsigned int);
                int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%X", num);
                buf_ptr += len;
                chars_printed += len;
            } else if (*ptr == '%') {
                // Print a literal '%'
                *buf_ptr++ = '%';
                chars_printed++;
            } else {
                // Unknown conversion specifier
                *buf_ptr++ = '%';  // Print the previous '%' character
                chars_printed++;
                *buf_ptr++ = *ptr;  // Print the unknown character
                chars_printed++;
            }
        } else {
            // Copy regular characters to the buffer
            *buf_ptr++ = *ptr;
            chars_printed++;
        }
        
        ptr++;  // Move to the next character
    }

    // Flush the remaining content of the buffer to stdout
    *buf_ptr = '\0';  // Null-terminate the buffer
    fputs(buffer, stdout);
    chars_printed += buf_ptr - buffer;

    va_end(args);
    return chars_printed;
}

int main() {
    _printf("Decimal: %d\n", 42);
    _printf("Unsigned decimal: %u\n", 255);
    _printf("Octal: %o\n", 123);
    _printf("Lowercase hexadecimal: %x\n", 255);
    _printf("Uppercase hexadecimal: %X\n", 255);
    _printf("Binary of 42: %b\n", 42);
    
    return 0;
}
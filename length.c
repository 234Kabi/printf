#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

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

            int flag_plus = 0;
            int flag_space = 0;
            int flag_hash = 0;

            // Handle flag characters
            while (*ptr == '+' || *ptr == ' ' || *ptr == '#') {
                if (*ptr == '+') {
                    flag_plus = 1;
                } else if (*ptr == ' ') {
                    flag_space = 1;
                } else if (*ptr == '#') {
                    flag_hash = 1;
                }
                ptr++;
            }

            int length_modifier = 0;  // 0 for no length modifier, 1 for 'h', 2 for 'l'

            // Handle length modifiers
            if (*ptr == 'h') {
                length_modifier = 1;
                ptr++;
            } else if (*ptr == 'l') {
                length_modifier = 2;
                ptr++;
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
                if (length_modifier == 1) {
                    short num = va_arg(args, int);  // short is promoted to int in va_arg
                    int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%+hd", num);
                    buf_ptr += len;
                    chars_printed += len;
                } else if (length_modifier == 2) {
                    long num = va_arg(args, long);
                    int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%+ld", num);
                    buf_ptr += len;
                    chars_printed += len;
                } else {
                    int num = va_arg(args, int);
                    int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%+d", num);
                    buf_ptr += len;
                    chars_printed += len;
                }
            } else if (*ptr == 'u') {
                // Print an unsigned integer in decimal format
                if (length_modifier == 1) {
                    unsigned short num = va_arg(args, unsigned int);  // short is promoted to int in va_arg
                    int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%hu", num);
                    buf_ptr += len;
                    chars_printed += len;
                } else if (length_modifier == 2) {
                    unsigned long num = va_arg(args, unsigned long);
                    int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%lu", num);
                    buf_ptr += len;
                    chars_printed += len;
                } else {
                    unsigned int num = va_arg(args, unsigned int);
                    int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%u", num);
                    buf_ptr += len;
                    chars_printed += len;
                }
            } else if (*ptr == 'o') {
                // Print an unsigned integer in octal format
                if (length_modifier == 1) {
                    unsigned short num = va_arg(args, unsigned int);  // short is promoted to int in va_arg
                    int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%#ho", num);
                    buf_ptr += len;
                    chars_printed += len;
                } else if (length_modifier == 2) {
                    unsigned long num = va_arg(args, unsigned long);
                    int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%#lo", num);
                    buf_ptr += len;
                    chars_printed += len;
                } else {
                    unsigned int num = va_arg(args, unsigned int);
                    int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%#o", num);
                    buf_ptr += len;
                    chars_printed += len;
                }
            } else if (*ptr == 'x') {
                // Print an unsigned integer in lowercase hexadecimal format
                if (length_modifier == 1) {
                    unsigned short num = va_arg(args, unsigned int);  // short is promoted to int in va_arg
                    int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%#hx", num);
                    buf_ptr += len;
                    chars_printed += len;
                } else if (length_modifier == 2) {
                    unsigned long num = va_arg(args, unsigned long);
                    int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%#lx", num);
                    buf_ptr += len;
                    chars_printed += len;
                } else {
                    unsigned int num = va_arg(args, unsigned int);
                    int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%#x", num);
                    buf_ptr += len;
                    chars_printed += len;
                }
            } else if (*ptr == 'X') {
                // Print an unsigned integer in uppercase hexadecimal format
                if (length_modifier == 1) {
                    unsigned short num = va_arg(args, unsigned int);  // short is promoted to int in va_arg
                    int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%#hX", num);
                    buf_ptr += len;
                    chars_printed += len;
                } else if (length_modifier == 2) {
                    unsigned long num = va_arg(args, unsigned long);
                    int len =
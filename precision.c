#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <main.h>

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

            int field_width = 0;

            // Handle field width
            while (*ptr >= '0' && *ptr <= '9') {
                field_width = field_width * 10 + (*ptr - '0');
                ptr++;
            }

            int precision = -1;

            // Handle precision
            if (*ptr == '.') {
                ptr++;  // Move past '.'
                precision = 0;
                while (*ptr >= '0' && *ptr <= '9') {
                    precision = precision * 10 + (*ptr - '0');
                    ptr++;
                }
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
                if (precision >= 0 && len > precision) {
                    len = precision;
                }
                if (field_width > 0 && len < field_width) {
                    int num_padding = field_width - len;
                    for (int i = 0; i < num_padding; i++) {
                        *buf_ptr++ = ' ';
                        chars_printed++;
                    }
                }
                strncpy(buf_ptr, s, len);
                buf_ptr += len;
                chars_printed += len;
            } else if (*ptr == 'd' || *ptr == 'i') {
                // Print a signed integer
                if (length_modifier == 1) {
                    short num = va_arg(args, int);  // short is promoted to int in va_arg
                    int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%+hd", num);
                    if (field_width > 0 && len < field_width) {
                        int num_padding = field_width - len;
                        for (int i = 0; i < num_padding; i++) {
                            *buf_ptr++ = ' ';
                            chars_printed++;
                        }
                    }
                    buf_ptr += len;
                    chars_printed += len;
                } else if (length_modifier == 2) {
                    long num = va_arg(args, long);
                    int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%+ld", num);
                    if (field_width > 0 && len < field_width) {
                        int num_padding = field_width - len;
                        for (int i = 0; i < num_padding; i++) {
                            *buf_ptr++ = ' ';
                            chars_printed++;
                        }
                    }
                    buf_ptr += len;
                    chars_printed += len;
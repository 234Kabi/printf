#include "main.h"
#include <stdio.h>
#include <stdarg.h>

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
    const char *ptr = format;

    while (*ptr != '\0') {
        if (*ptr == '%') {
            ptr++;  // Move past '%'
            
            if (*ptr == '\0') {
                // Reached end of format string
                break;
            }
            
            if (*ptr == 'c') {
                // Print a character
                char c = va_arg(args, int);
                putchar(c);
                chars_printed++;
            } else if (*ptr == 's') {
                // Print a string
                char *s = va_arg(args, char *);
                fputs(s, stdout);
                chars_printed += strlen(s);
            } else if (*ptr == 'd' || *ptr == 'i') {
                // Print a signed integer
                int num = va_arg(args, int);
                printf("%d", num);
                chars_printed += snprintf(NULL, 0, "%d", num);  // Calculate printed characters
            } else if (*ptr == 'u') {
                // Print an unsigned integer in decimal format
                unsigned int num = va_arg(args, unsigned int);
                printf("%u", num);
                chars_printed += snprintf(NULL, 0, "%u", num);  // Calculate printed characters
            } else if (*ptr == 'o') {
                // Print an unsigned integer in octal format
                unsigned int num = va_arg(args, unsigned int);
                printf("%o", num);
                chars_printed += snprintf(NULL, 0, "%o", num);  // Calculate printed characters
            } else if (*ptr == 'x') {
                // Print an unsigned integer in lowercase hexadecimal format
                unsigned int num = va_arg(args, unsigned int);
                printf("%x", num);
                chars_printed += snprintf(NULL, 0, "%x", num);  // Calculate printed characters
            } else if (*ptr == 'X') {
                // Print an unsigned integer in uppercase hexadecimal format
                unsigned int num = va_arg(args, unsigned int);
                printf("%X", num);
                chars_printed += snprintf(NULL, 0, "%X", num);  // Calculate printed characters
            } else if (*ptr == '%') {
                // Print a literal '%'
                putchar('%');
                chars_printed++;
            } else {
                // Unknown conversion specifier
                putchar('%');  // Print the previous '%' character
                chars_printed++;
                putchar(*ptr);  // Print the unknown character
                chars_printed++;
            }
        } else {
            // Print regular characters
            putchar(*ptr);
            chars_printed++;
        }
        
        ptr++;  // Move to the next character
    }

    va_end(args);
    return chars_printed;
}

int main() {
    _printf("Decimal: %d\n", 42);
    _printf("Unsigned decimal: %u\n", 255);
    _printf("Octal: %o\n", 123);
    _printf("Lowercase hexadecimal: %x\n", 255);
    _printf("Uppercase hexadecimal: %X\n", 255);
    
    return 0;
}
#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
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
            } else if (*ptr == '%') {
                // Print a literal '%'
                putchar('%');
                chars_printed++;
            } else {
                // Invalid conversion specifier
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
    _printf("Hello, %s!\n", "world");
    _printf("The character is %c\n", 'A');
    _printf("This is a percent sign: %%\n");
    
    return 0;
}
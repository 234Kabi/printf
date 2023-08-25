#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
#include <stdio.h>
#include <stdarg.h>

int my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    int printed_chars = 0;
    const char *ptr = format;

    while (*ptr != '\0') {
        if (*ptr == '%') {
            ptr++; // Move past '%'
            
            // Check for precision
            int precision = -1; // Default value
            if (*ptr == '.') {
                ptr++; // Move past '.'
                precision = 0;
                while (*ptr >= '0' && *ptr <= '9') {
                    precision = precision * 10 + (*ptr - '0');
                    ptr++;
                }
            }

            // Check for conversion specifier
            if (*ptr == 'f') {
                double value = va_arg(args, double);
                if (precision >= 0) {
                    // Round or truncate the value to the specified precision
                    double factor = 1;
                    for (int i = 0; i < precision; i++) {
                        factor *= 10;
                    }
                    value = round(value * factor) / factor;
                }
                printed_chars += printf("%.2f", value); // Fixed to 2 decimal places
            } else {
                // Handle other conversion specifiers here
            }
        } else {
            putchar(*ptr);
            printed_chars++;
        }
        ptr++;
    }

    va_end(args);
    return printed_chars;
}

int main() {
    double number = 3.14159265;
    my_printf("Formatted number: %.2f\n", number);

    return 0;
}
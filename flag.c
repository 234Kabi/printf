  #include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Additional arguments based on format
 * Return: Number of characters printed
 */
int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int printed_chars = 0;
    const char *ptr = format;

    while (*ptr != '\0') {
        if (*ptr == '%') {
            ptr++; // Move past '%'

            // Initialize flags
            bool flag_plus = false;
            bool flag_space = false;
            bool flag_hash = false;

            // Handle flag characters
            while (*ptr == '+' || *ptr == ' ' || *ptr == '#') {
                if (*ptr == '+')
                    flag_plus = true;
                else if (*ptr == ' ')
                    flag_space = true;
                else if (*ptr == '#')
                    flag_hash = true;
                ptr++;
            }

            // Handle conversion specifier
            if (*ptr == 'd' || *ptr == 'i') {
                int value = va_arg(args, int);
                // Apply flags here
                if (flag_plus && value >= 0)
                    printed_chars += putchar('+');
                else if (flag_space && value >= 0)
                    printed_chars += putchar(' ');
                // Print the value
                printed_chars += printf("%d", value);
            } else if (*ptr == 'x' || *ptr == 'X') {
                unsigned int value = va_arg(args, unsigned int);
                // Apply flags here
                if (flag_hash) {
                    if (*ptr == 'x')
                        printed_chars += printf("0x");
                    else
                        printed_chars += printf("0X");
                }
                // Print the value
                printed_chars += printf(*ptr == 'x' ? "%x" : "%X", value);
            } else {
                // Handle other conversion specifiers
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

int main(void) {
    int num = 42;
    unsigned int hex_num = 0xABC;
    _printf("Number: %d\n", num);
    _printf("Hex Number: %#x\n", hex_num);

    return 0;
}
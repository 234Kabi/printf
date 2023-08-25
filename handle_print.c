 #include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
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
            } else if (*ptr == 'd' || *ptr == 'i') {
                // Print an integer
                int num = va_arg(args, int);
                printf("%d", num);
                chars_printed += snprintf(NULL, 0, "%d", num);  // Calculate printed characters
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
    _printf("Hello, %s!\n", "world");
    _printf("The character is %c\n", 'A');
    _printf("This is a percent sign: %%\n");
    _printf("The number is %d\n", 42);
    _printf("Another number: %i\n", -123);
    
    return 0;
}
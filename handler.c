                } else {
                    int num = va_arg(args, int);
                    int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%+d", num);
                    if (field_width > 0) {
                        int num_padding = field_width - len;
                        if (flag_zero) {
                            char sign = (num < 0 || flag_plus || flag_space) ? *buf_ptr : ' ';
                            if (sign != ' ') {
                                *buf_ptr++ = sign;
                                chars_printed++;
                                len--;
                                num_padding--;
                            }
                            for (int i = 0; i < num_padding; i++) {
                                *buf_ptr++ = '0';
                                chars_printed++;
                            }
                        } else {
                            for (int i = 0; i < num_padding; i++) {
                                *buf_ptr++ = ' ';
                                chars_printed++;
                            }
                        }
                    }
                    buf_ptr += len;
                    chars_printed += len;
                }
            } else if (*ptr == 'u') {
                // Print an unsigned integer in decimal format
                if (length_modifier == 1) {
                    unsigned short num = va_arg(args, unsigned int);  // short is promoted to int in va_arg
                    int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%hu", num);
                    if (field_width > 0) {
                        int num_padding = field_width - len;
                        if (flag_zero) {
                            for (int i = 0; i < num_padding; i++) {
                                *buf_ptr++ = '0';
                                chars_printed++;
                            }
                        } else {
                            for (int i = 0; i < num_padding; i++) {
                                *buf_ptr++ = ' ';
                                chars_printed++;
                            }
                        }
                    }
                    buf_ptr += len;
                    chars_printed += len;
                } else if (length_modifier == 2) {
                    unsigned long num = va_arg(args, unsigned long);
                    int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%lu", num);
                    if (field_width > 0) {
                        int num_padding = field_width - len;
                        if (flag_zero) {
                            for (int i = 0; i < num_padding; i++) {
                                *buf_ptr++ = '0';
                                chars_printed++;
                            }
                        } else {
                            for (int i = 0; i < num_padding; i++) {
                                *buf_ptr++ = ' ';
                                chars_printed++;
                            }
                        }
                    }
                    buf_ptr += len;
                    chars_printed += len;
                } else {
                    unsigned int num = va_arg(args, unsigned int);
                    int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%u", num);
                    if (field_width > 0) {
                        int num_padding = field_width - len;
                        if (flag_zero) {
                            for (int i = 0; i < num_padding; i++) {
                                *buf_ptr++ = '0';
                                chars_printed++;
                            }
                        } else {
                            for (int i = 0; i < num_padding; i++) {
                                *buf_ptr++ = ' ';
                                chars_printed++;
                            }
                        }
                    }
                    buf_ptr += len;
                    chars_printed += len;
                }
            } else if (*ptr == 'o') {
                // Print an unsigned integer in octal format
                if (length_modifier == 1) {
                    unsigned short num = va_arg(args, unsigned int);  // short is promoted to int in va_arg
                    int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%#ho", num);
                    if (field_width > 0) {
                        int num_padding = field_width - len;
                        if (flag_zero) {
                            char sign = (num < 0 || flag_plus || flag_space) ? *buf_ptr : ' ';
                            if (sign != ' ') {
                                *buf_ptr++ = sign;
                                chars_printed++;
                                len--;
                                num_padding--;
                            }
                            *buf_ptr++ = '0';
                            chars_printed++;
                            for (int i = 0; i < num_padding; i++) {
                                *buf_ptr++ = '0';
                                chars_printed++;
                            }
                        } else {
                            for (int i = 0; i < num_padding; i++) {
                                *buf_ptr++ = ' ';
                                chars_printed++;
                            }
                        }
                    }
                    buf_ptr += len;
                    chars_printed += len;
                } else if (length_modifier == 2) {
                    unsigned long num = va_arg(args, unsigned long);
                    int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%#lo", num);
                    if (field_width > 0) {
                        int num_padding = field_width - len;
                        if (flag_zero) {
                            char sign = (num < 0 || flag_plus || flag_space) ? *buf_ptr : ' ';
                            if (sign != ' ') {
                                *buf_ptr++ = sign;
                                chars_printed++;
                                len--;
                                num_padding--;
                            }
                            *buf_ptr++ = '0';
                            chars_printed++;
                            for (int i = 0; i < num_padding; i++) {
                                *buf_ptr++ = '0';
                                chars_printed++;
                            }
                        } else {
                            for (int i = 0; i < num_padding; i++) {
                                *buf_ptr++ = ' ';
                                chars_printed++;
                            }
                        }
                    }
                    buf_ptr += len;
                    chars_printed += len;
                } else {
                    unsigned int num = va_arg(args, unsigned int);
                    int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%#o", num);
                    if (field_width > 0) {
                        int num_padding = field_width - len;
                        if (flag_zero) {
                            char sign = (num < 0 || flag_plus || flag_space) ? *buf_ptr : ' ';
                            if (sign != ' ') {
                                *buf_ptr++ = sign;
                                chars_printed++;
                                len--;
                                num_padding--;
                            }
                            *buf_ptr++ = '0';
                            chars_printed++;
                            for (int i = 0; i < num_padding; i++) {
                                *buf_ptr++ = '0';
                                chars_printed++;
                            }
                        } else {
                            for (int i = 0; i < num_padding; i++) {
                                *buf_ptr++ = ' ';
                                chars_printed++;
                            }
                        }
                    }
                    buf_ptr += len;
                    chars_printed += len;
                }
            } else if (*ptr == 'x') {
                // Print an unsigned integer in lowercase hexadecimal format
                if (length_modifier == 1) {
                    unsigned short num = va_arg(args, unsigned int);  // short is promoted to int in va_arg
                    int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%#hx", num);
                    if (field_width > 0) {
                        int num_padding = field_width - len;
                        if (flag_zero) {
                            char sign = (num < 0 || flag_plus || flag_space) ? *buf_ptr : ' ';
                            if (sign != ' ') {
                                *buf_ptr++ = sign;
                                chars_printed++;
                                len--;
                                num_padding--;
                            }
                            *buf_ptr++ = '0';
                            chars_printed++;
                            for (int i = 0; i < num_padding; i++) {
                                *buf_ptr++ = '0';
                                chars_printed++;
                            }
                        } else {
                            for (int i = 0; i < num_padding; i++) {
                                *buf_ptr++ = ' ';
                                chars_printed++;
                            }
                        }
                    }
                    buf_ptr += len;
                    chars_printed += len;
                } else if (length_modifier == 2) {
                    unsigned long num = va_arg(args, unsigned long);
                    int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%#lx", num);
                    if (field_width > 0) {
                        int num_padding = field_width - len;
                        if (flag_zero) {
                            char sign = (num < 0 || flag_plus || flag_space) ? *buf_ptr : ' ';
                            if (sign != ' ') {
                                *buf_ptr++ = sign;
                                chars_printed++;
                                len--;
                                num_padding--;
                            }
                            *buf_ptr++ = '0';
                            chars_printed++;
                            for (int i = 0; i < num_padding; i++) {
                                *buf_ptr++ = '0';
                                chars_printed++;
                            }
                        } else {
                            for (int i = 0; i < num_padding; i++) {
                                *buf_ptr++ = ' ';
                                chars_printed++;
                            }
                        }
                    }
                    buf_ptr += len;
                    chars_printed += len;
                } else {
                    unsigned int num = va_arg(args, unsigned int);
                    int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%#x", num);
                    if (field_width > 0) {
                        int num_padding = field_width - len;
                        if (flag_zero) {
                            char sign = (num < 0 || flag_plus || flag_space) ? *buf_ptr : ' ';
                            if (sign != ' ') {
                                *buf_ptr++ = sign;
                                chars_printed++;
                                len--;
                                num_padding--;
                            }
                            *buf_ptr++ = '0';
                            chars_printed++;
                            for (int i = 0; i < num_padding; i++) {
                                *buf_ptr++ = '0';
                                chars_printed++;
                            }
                        } else {
                            for (int i = 0; i < num_padding; i++) {
                                *buf_ptr++ = ' ';
                                chars_printed++;
                            }
                        }
                    }
                    buf_ptr += len;
                    chars_printed += len;
                }
            } else if (*ptr == 'X') {
                // Print an unsigned integer in uppercase hexadecimal format
                if (length_modifier == 1) {
                    unsigned short num = va_arg(args, unsigned int);  // short is promoted to int in va_arg
                    int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%#hX", num);
                    if (field_width > 0) {
                        int num_padding = field_width - len;
                        if (flag_zero) {
                            char sign = (num < 0 || flag_plus || flag_space) ? *buf_ptr : ' ';
                            if (sign != ' ') {
                                *buf_ptr++ = sign;
                                chars_printed++;
                                len--;
                                num_padding--;
                            }
                            *buf_ptr++ = '0';
                            chars_printed++;
                            for (int i = 0; i < num_padding; i++) {
                                *buf_ptr++ = '0';
                                chars_printed++;
                            }
                        } else {
                            for (int i = 0; i < num_padding; i++) {
                                *buf_ptr++ = ' ';
                                chars_printed++;
                            }
                        }
                    }
                    buf_ptr += len;
                    chars_printed += len;
                } else if (length_modifier == 2) {
                    unsigned long num = va_arg(args, unsigned long);
                    int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%#lX", num);
                    if (field_width > 0) {
                        int num_padding = field_width - len;
                        if (flag_zero) {
                            char sign = (num < 0 || flag_plus || flag_space) ? *buf_ptr : ' ';
                            if (sign != ' ') {
                                *buf_ptr++ = sign;
                                chars_printed++;
                                len--;
                                num_padding--;
                            }
                            *buf_ptr++ = '0';
                            chars_printed++;
                            for (int i = 0; i < num_padding; i++) {
                                *buf_ptr++ = '0';
                                chars_printed++;
                            }
                        } else {
                            for (int i = 0; i < num_padding; i++) {
                                *buf_ptr++ = ' ';
                                chars_printed++;
                            }
                        }
                    }
                    buf_ptr += len;
                    chars_printed += len;
                } else {
                    unsigned int num = va_arg(args, unsigned int);
                    int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%#X", num);
                    if (field_width > 0) {
                        int num_padding = field_width - len;
                        if (flag_zero) {
                            char sign = (num < 0 || flag_plus || flag_space) ? *buf_ptr : ' ';
                            if (sign != ' ') {
                                *buf_ptr++ = sign;
                                chars_printed++;
                                len--;
                                num_padding--;
                            }
                            *buf_ptr++ = '0';
                            chars_printed++;
                            for (int i = 0; i < num_padding; i++) {
                                *buf_ptr++ = '0';
                                chars_printed++;
                            }
                        } else {
                            for (int i = 0; i < num_padding; i++) {
                                *buf_ptr++ = ' ';
                                chars_printed++;
                            }
                        }
                    }
                    buf_ptr += len;
                    chars_printed += len;
                }
            }
            ptr++;
        } else {
            // Regular character, copy to buffer
            *buf_ptr++ = *ptr++;
            chars_printed++;
        }
    }

    // Write remaining content in buffer to stdout
    if (buf_ptr != buffer) {
        *buf_ptr = '\0';  // Null-terminate the buffer
        fputs(buffer, stdout);
        chars_printed += buf_ptr - buffer;
    }

    va_end(args);
    return chars_printed;
}

int main() {
    _printf("Hello, %d!\n", 42);
    _printf("Value: %04d\n", 12);
    _printf("Hex: %#x\n", 255);
    _printf("Octal: %#o\n", 63);
    _printf("Binary: %b\n", 15);  // Custom binary specifier (for demonstration)
    return 0;
}
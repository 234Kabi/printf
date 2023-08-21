            } else {
                unsigned int num = va_arg(args, unsigned int);
                int len = snprintf(buf_ptr, BUFFER_SIZE - (buf_ptr - buffer), "%#X", num);
                if (field_width > 0) {
                    int num_padding = field_width - len;
                    if (flag_minus) {
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
                            *buf_ptr++ = ' ';
                            chars_printed++;
                        }
                    } else if (flag_zero) {
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
                        char sign = (num < 0 || flag_plus || flag_space) ? *buf_ptr : ' ';
                        if (sign != ' ') {
                            *buf_ptr++ = sign;
                            chars_printed++;
                            len--;
                        }
                        *buf_ptr++ = '0';
                        chars_printed++;
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
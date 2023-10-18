#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int printed_chars = 0;
    char c;

    while (*format) {
        if (*format == '%') {
            format++; // Move past the '%'
            if (*format == '\0') {
                break; // Ignore trailing '%'
            }

            if (*format == 'c') {
                c = va_arg(args, int); // Get the character argument
                putchar(c);
                printed_chars++;
            } else if (*format == 's') {
                char *str = va_arg(args, char *); // Get the string argument
                while (*str) {
                    putchar(*str);
                    str++;
                    printed_chars++;
                }
            } else if (*format == '%') {
                putchar('%');
                printed_chars++;
            }
        } else {
            putchar(*format);
            printed_chars++;
        }
        format++;
    }

    va_end(args);
    return printed_chars;
}

int main() {
    char c = 'X';
    char *str = "Hello, World!";

    int num_chars = _printf("I'm not going anywhere. You can print that wherever you want to. I'm here and I'm a Spur for life: %c, %s%%\n", c, str);
    printf("\nTotal characters printed: %d\n", num_chars);

    return 0;
}

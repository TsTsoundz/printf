#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
char fmt;
int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);

int handle_print(const char *format, int *counter, va_list argslist,
char tempBuffer[],
int activeFlags, int textwidth, int valuePrecision, int typeSize);

/****************** FUNCTIONS ******************/

/* Functions to print chars and strings */
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non-printable characters */
int print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* Function to print memory address */
int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int acquire_flags(const char *format, int *counter);
int acquire_width(const char *format, int *counter, va_list argslist);
int acquire_precision(const char *format, int *counter, va_list argslist);
int acquire_size(const char *format, int *counter);

/* Function to print string in reverse */
int print_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* Function to print a string in ROT13 */
int print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* Width handler */
int handle_write_char(char c, char tempBuffer[],
int activeFlags, int textwidth, int valueprecision, int typesize);
int write_number(int is_negative, int ind, char buffer[],
int activeFlags, int textwidth, int valueprecision, int typesize);
int write_num(int ind, char bff[], int flags,
int width, int prec, int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
int width, int flags, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int ind, char buffer[],
int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */

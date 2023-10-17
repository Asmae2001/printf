#include "main.h"

<<<<<<< HEAD
=======
void print_buffer(char buffer[], int *buff_ind);

>>>>>>> c574df603ca26779fd9cdb7155ae3c9e14510638
/**
 * _printf - Receives the main string and all the necessary parameters to
 * print a formated string
 * @format: A string containing all the desired characters
 * Return: A total count of the characters printed
 */

int _printf(const char *format, ...)
{
<<<<<<< HEAD
	int printed_chars;
	conver_t f_list[] = {
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"c", print_char},
		{"s", print_string},
		{"b", print_binary},
		{"u", print_unsigned_integer},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_HEX},
		{"S", print_String},
		{"p", print_pointer},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL},
	};
	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	printed_chars = format_reciever(format, f_list, arg_list);
	va_end(arg_list);
	return (printed_chars);
}
=======
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}


>>>>>>> c574df603ca26779fd9cdb7155ae3c9e14510638

#include <xtostr.h>
#include <stdbool.h>
#include <stdint.h>

/*
 * itostr
 *
 * Converts an integer into a string.
 *
 * It takes the pointer to a buffer str[] of size XTOSTR_ARRAY_SIZE, and a number
 * to stringify, number.
 */
void itostr(char str[XTOSTR_ARRAY_SIZE], int number)
{

	int r_index = 0;
	int s_index = 0;

	char reversed[XTOSTR_ARRAY_SIZE+1];

	if (number == 0)
	{
		str[0] =  '0';
		str[1] = '\0';
		return;
	}

	if (number < 0)
	{
		str[0] = '-';
		number = -number;
		s_index++;
	}

	while (number)
	{
		int module = number % 10;
		reversed[r_index++] = module + '0';
		number /= 10;
	}

	r_index--;
	while (r_index >= 0) str[s_index++] = reversed[r_index--], str[s_index] = '\0';

	return;
}

/*
 * xtostr
 *
 * Converts an (hex) integer into a string.
 */
void xtostr(char str[XTOSTR_ARRAY_SIZE], uint32_t number)
{

	int  index = 0;
	char reversed[XTOSTR_ARRAY_SIZE+1];

	int digits_left = 8;

	while (digits_left--)
	{

		short digit = number & 0b1111;

		char character = (char) digit + '0';

		/* Shift number into alpha */
		if (character > '9') character += (0x10 - 0x9);

		reversed[index++] = character;

		number >>= 4;
	}

	str[0] = '0', str[1] = 'x';

	int top = index;
	for (int i = 0; i < top; i++) str[i+2] = reversed[--index], str[i+3] = '\0';

	return;
}
/*
 * lxtostr
 *
 * Converts an (hex) long integer into a string.
 */
void lxtostr(char str[XTOSTR_ARRAY_SIZE], uint64_t number)
{

	int  index = 0;
	char reversed[XTOSTR_ARRAY_SIZE+1];

	int digits_left = 16;

	while (digits_left--)
	{

		short digit = number & 0b1111;

		char character = (char) digit + '0';

		/* Shift number into alpha */
		if (character > '9') character += (0x10 - 0x9);

		reversed[index++] = character;

		number >>= 4;
	}

	str[0] = '0', str[1] = 'x';

	int top = index;
	for (int i = 0; i < top; i++) str[i+2] = reversed[--index], str[i+3] = '\0';

	return;
}

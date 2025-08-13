/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/14 14:27:13 by bamarell      #+#    #+#                 */
/*   Updated: 2023/10/24 16:53:16 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/ft_printf.h"
#include "libft/string.h"
#include "libft/ctype.h"
#include "libft/math.h"

// Get the flag of a format based on their character.
static int	get_format_flag(char c)
{
	if (c == '-')
		return (FLAGS_LEFT_JUSTIFY);
	if (c == '+')
		return (FLAGS_PRECEED_SIGN);
	if (c == ' ')
		return (FLAGS_PRECEED_SPACE);
	if (c == '#')
		return (FLAGS_PRECEED_ZERO);
	if (c == '0')
		return (FLAGS_PAD_ZERO);
	return (FLAGS_NONE);
}

//
// Handles both precision and width
//
static int	parse_format_number(const char **fmt, va_list args)
{
	int	value;

	value = 0;
	if (**fmt == '*' && (*fmt)++)
		value = va_arg(args, int);
	else if (ft_isdigit(**fmt))
	{
		while (ft_isdigit(**fmt))
			value = value * 10 + (*(*fmt)++ - '0');
	}
	return (value);
}

// TODO(fix): If we already had assigned H, that means we have a
// double h (hh) however, it doesn't necessarily mean it's sequential.
static int	get_format_length(t_format format, char c)
{
	if (c == 'h')
	{
		if (format.length & LENGTH_H)
			return (LENGTH_HH);
		return (LENGTH_H);
	}
	else if (c == 'l')
	{
		if (format.length & LENGTH_L)
			return (LENGTH_LL);
		return (LENGTH_L);
	}
	else if (c == 'j')
		return (LENGTH_J);
	else if (c == 'z')
		return (LENGTH_Z);
	else if (c == 't')
		return (LENGTH_T);
	else if (c == 'L')
		return (LENGTH_L);
	return (LENGTH_NONE);
}

//
// We check for the '%' character upfront since it's passed directly
// primarily only when we test this function outside of it's actual
// use.
//
// We format the format like the following:
// 1. Check for all the flags and add it to the bit field.
// 2. Update the pad if necessary (if `FLAGS_PAD_ZERO` was set)
// 3. Parse the "width" if necessary.
// 4. Parse the "precision" if necessary.
// 5. Check for all the conversions and add it to the bit field.
// 6. Double check to make sure the character we're currently at
// is actually a valid & supported specifier.
//
t_format	parse_format(const char **fmt, va_list args)
{
	t_format	format;

	init_format(&format);
	if (**fmt == '%')
		(*fmt)++;
	while (ft_strchr(FORMAT_FLAGS, **fmt))
		format.flags |= get_format_flag(*(*fmt)++);
	if (format.flags & FLAGS_PAD_ZERO)
		format.pad = '0';
	if (**fmt == '*' || ft_isdigit(**fmt))
		format.width = parse_format_number(fmt, args);
	if (format.width < 0)
	{
		format.flags |= FLAGS_LEFT_JUSTIFY;
		format.width = ft_abs(format.width);
	}
	if (**fmt == '.' && (*fmt)++)
		format.precision = parse_format_number(fmt, args);
	while (ft_strchr(FORMAT_LENGTH, **fmt))
		format.length |= get_format_length(format, *(*fmt)++);
	if (ft_strchr(FORMAT_SPECIFIERS, **fmt))
		format.specifier = *(*fmt)++;
	if (format.precision > -1 && format.flags & FLAGS_PAD_ZERO)
		format.pad = ' ';
	return (format);
}

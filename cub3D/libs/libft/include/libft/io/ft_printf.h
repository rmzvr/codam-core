/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bamarell <bamarell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 11:48:42 by bamarell      #+#    #+#                 */
/*   Updated: 2023/11/28 14:17:11 by bamarell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>

# define FORMAT_FLAGS "-+ #0"
# define FORMAT_LENGTH "hljztL"
# define FORMAT_SPECIFIERS "diuoxXcsp%"

# define LOW_BASE_16 "0123456789abcdef"
# define UP_BASE_16 "0123456789ABCDEF"
# define BASE_10 "0123456789"

//
// A general purpose function prototype dedicated to
// handling / writing to the desired output.
//
// Length parameter is necessary because we don't
// know how long the string provided is. We could
// theorethically check it's length in the callback
// but if the length is calculated and modified with
// precision / width flags, it's easier to handle like
// this.
//
struct		s_stream;
struct		s_stream_io;

typedef int	(*t_stream_cb)(struct s_stream *st, const char *s, size_t length);

typedef struct s_stream_io
{
	char	*wbase;
	// r/w ptr
	char	*wptr;
	// r/w end
	char	*wend;
	// max len of buffer
	size_t	size;
}	t_stream_io;

typedef struct s_stream
{
	int			fd;
	t_stream_cb	callback;
	t_stream_io	*io;
}	t_stream;

extern int		stdstream_write(t_stream *st, const char *fmt, size_t length);

typedef struct s_format
{
	char	specifier;
	char	pad;
	int		precision;
	int		flags;
	int		width;
	int		length;
}	t_format;

//
// FLAGS_PREPEND_*
//
// |        FLAG         | CHARACTER |
// |---------------------|-----------|
// | FLAG_NONE           |           |
// | FLAGS_LEFT_JUSTIFY  | '-'       |
// | FLAGS_PRECEED_SIGN  | '+'       |
// | FLAGS_PRECEED_SPACE | ' '       |
// | FLAGS_PRECEED_ZERO  | '#'       |
// | FLAGS_PAD_ZERO      | '0'       |
//
enum e_format_flags
{
	FLAGS_NONE = 0,
	FLAGS_LEFT_JUSTIFY = 1,
	FLAGS_PRECEED_SIGN = 2,
	FLAGS_PRECEED_SPACE = 4,
	FLAGS_PRECEED_ZERO = 8,
	FLAGS_PAD_ZERO = 16,
};

//
// |   LENGTH    | CHARACTER(S) |
// |-------------|--------------|
// | LENGTH_NONE |              |
// | LENGTH_HH   | "hh"         |
// | LENGTH_H    | "h"          |
// | LENGTH_L    | "l"          |
// | LENGTH_LL   | "ll"         |
// | LENGTH_J    | "j"          |
// | LENGTH_Z    | "z"          |
// | LENGTH_T    | "t"          |
// | LENGTH_LLL  | "L"          |
//
enum e_format_length
{
	LENGTH_NONE = 0,
	LENGTH_HH = 1,
	LENGTH_H = 2,
	LENGTH_L = 4,
	LENGTH_LL = 8,
	LENGTH_J = 16,
	LENGTH_Z = 32,
	LENGTH_T = 64,
	LENGTH_LLL = 128,
};

// format.c
extern void		init_format(t_format *format);
// parser.c
extern t_format	parse_format(const char **fmt, va_list args);

// ft_vsprintf.c
extern int		ft_vsnprintf(char *b, size_t n, const char *fmt, va_list args);
// ft_vsprintf.c
extern int		ft_vsprintf(char *buf, const char *fmt, va_list args);
// ft_sprintf.c
extern int		ft_sprintf(char *buf, const char *fmt, ...)
				__attribute__((format(printf, 2, 3)));
// ft_snprintf.c
extern int		ft_snprintf(char *buf, size_t n, const char *fmt, ...)
				__attribute__((format(printf, 3, 4)));
// ft_vfprintf.c
extern int		ft_vfprintf(t_stream *stream, const char *fmt, va_list args);
// ft_fprintf.c
extern int		ft_fprintf(t_stream *stream, const char *fmt, ...)
				__attribute__((format(printf, 2, 3)));
// ft_vdprintf.c
extern int		ft_vdprintf(int fd, const char *fmt, va_list args);
// ft_dprintf.c
extern int		ft_dprintf(int fd, const char *fmt, ...)
				__attribute__((format(printf, 2, 3)));
// ft_vprintf.c
extern int		ft_vprintf(const char *fmt, va_list args);
// ft_printf.c
extern int		ft_printf(const char *format, ...)
				__attribute__((format(printf, 1, 2)));

// Formatters (perhaps move to fmt.h or something alike)
extern int		handle_format(t_stream *stream, t_format format, va_list args);
extern size_t	ft_write_pad(t_stream *stream, char pad, int length);
extern size_t	ft_write_n(t_stream *str, t_format f, char *s, long int val);
extern size_t	ft_write_s(t_stream *stream, t_format format, char *str);
extern size_t	ft_fmtc(t_stream *stream, t_format format, va_list args);
extern size_t	ft_fmts(t_stream *stream, t_format format, va_list args);
extern size_t	ft_fmtdi(t_stream *stream, t_format format, va_list args);
extern size_t	ft_fmtx(t_stream *stream, t_format format, va_list args);
extern size_t	ft_fmtu(t_stream *stream, t_format format, va_list args);
extern size_t	ft_fmtp(t_stream *stream, t_format format, va_list args);
#endif

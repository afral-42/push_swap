/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:55:56 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/25 17:44:35 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include <stddef.h>
# include <stdarg.h>
# include <sys/types.h>
# include <stdint.h>

# define FLAGS "#0-+ "

typedef enum e_type
{
	UNDEFINED,
	INT,
	UINT,
	HEX,
	CHAR,
	STR,
	PTR,
	PCT,
}	t_type;

typedef union u_arg
{
	int				i;
	unsigned int	ui;
	uintptr_t		p;
	char			c;
	char			*s;
}	t_arg;

typedef struct s_specifiers
{
	int		flags[127];
	int		width;
	int		precision;
	int		precision_set;
	int		to_upper;
	t_type	type;
	t_arg	arg;
}	t_specifiers;

// specifiers functions
t_specifiers	new_specifiers(void);

// parsers & parsers helpers
ssize_t			parse_unformatted(const char *s);
ssize_t			parse_formatted(const char *s, va_list vargs);
ssize_t			out(const char *s, size_t l);
t_type			gettype(const char c);
t_arg			getarg(t_type type, va_list	vargs);

//prefix
ssize_t			prefix(t_specifiers specifiers);
int				get_prefix_size(t_specifiers specifiers);

//formatters helpers
ssize_t			format_value(t_specifiers specifiers);
ssize_t			format_hex(t_specifiers specifiers);
ssize_t			format_uint(t_specifiers specifiers);
ssize_t			format_int(t_specifiers specifiers);
ssize_t			format_ptr(t_specifiers specifiers);
ssize_t			format_str(t_specifiers specifiers);
ssize_t			format_chr(t_specifiers specifiers);
ssize_t			ft_putnbr_base(unsigned long n, int precision, char *base);

#endif

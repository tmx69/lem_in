/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:56:40 by jritchie          #+#    #+#             */
/*   Updated: 2019/03/08 10:56:45 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <wchar.h>
# include <locale.h>
# include <limits.h>
# define MIN(x, y) (x < y ? x : y)
# define MAX(x, y) (x > y ? x : y)

typedef struct	s_hodl
{
	int		i;
	int		minus;
	int		space;
	int		sign;
	int		plus;
}				t_hodl;

typedef struct	s_parse
{
	int		flag[6];
	int		widht;
	int		prec;
	char	*lenght;
	char	type;
	int		size;
	int		pzero;
	int		nul;
	char	per;
	int		q;
	int		fminus;
	int		sign;
	int		pm;
}				t_parse;

int				ft_printf(const char *restrict format, ...);
void			print_left_s(char *a, t_parse *one, t_hodl *size, int l);
void			print_right_s(char *a, t_parse *one, t_hodl *size, int l);
int				parsing_s(va_list arg, t_parse *one, t_hodl *size);
void			print_left_o(uintmax_t i, t_parse *one, t_hodl *size, int l);
void			print_right_o(uintmax_t i, t_parse *one, t_hodl *size, int l);
int				parsing_o(va_list arg, t_parse *one, t_hodl *size);
void			to_hex_pointer(uintmax_t n, t_parse *one, unsigned int base,
				t_hodl *size);
int				parsing_di(va_list arg, t_parse *one, t_hodl *size);
void			print_right_di(char *ar, t_parse *one, t_hodl *size, int l);
void			print_left_di(char *ar, t_parse *one, t_hodl *size, int l);
int				parsing_c(va_list arg, t_parse *one, t_hodl *size);
int				parsing_p(va_list arg, t_parse *one, t_hodl *size);
int				parsing_per(t_parse *one, t_hodl *size);
char			*ft_parse_type(char *format, t_parse *one);
char			*ft_parse_lenght(char *format, t_parse *one);
char			*ft_parse_prec(char	*format, va_list arg, t_parse *one);
char			*ft_parse_widht(char *format, va_list arg, t_parse *one);
char			*ft_parse_flags(char *format, t_parse *one);
int				to_hex(uintmax_t n, unsigned int base, int i, t_parse *one);
void			print_left_x(uintmax_t i, t_parse *one, t_hodl *size, int l);
void			print_right_x(uintmax_t i, t_parse *one, t_hodl *size, int l);
int				parsing_x(va_list arg, t_parse *one, t_hodl *size);
int				ft_putnstrn(char const *s, size_t num);
int				parsing_u(va_list arg, t_parse *one, t_hodl *size);
void			print_right_u(char *ar, t_parse *one, t_hodl *size, int l);
void			print_left_u(char *ar, t_parse *one, t_hodl *size, int l);
uintmax_t		cast_unsigned(uintmax_t n, va_list arg, t_parse *one);
intmax_t		cast_signed(intmax_t n, va_list arg, t_parse *one);
void			print_prec(char *ar, t_parse *one, t_hodl *size, int l);
void			print_widht(char *ar, t_parse *one, t_hodl *size, int l);
char			*ft_uitoa(unsigned long long n);
void			parsing_f(va_list arg, t_parse *one, t_hodl *size);
char			*prin_f2(char *a);
char			*prinf2(char *a, int i, int flag);
char			*prin_f(char *a);
char			*print_left_f(char *ar, t_parse *one);
void			b_minus(char *a, t_parse *one, t_hodl *size);
char			*prinf2(char *a, int i, int flag);
char			*prinf(char *a, int i);
char			*znak(char *a, t_parse *one);
char			*sign(char *a, t_parse *one);
char			*mp(char *a, t_parse *one);
char			*hashf(char *a, t_parse *one);

#endif

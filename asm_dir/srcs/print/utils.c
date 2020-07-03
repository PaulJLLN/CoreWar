/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albanbotier <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 22:02:08 by albanboti         #+#    #+#             */
/*   Updated: 2020/06/12 17:13:16 by albanboti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prototypes.h"
#include "../../includes/ft_printf.h"
#include <unistd.h>

char		*atoi_jr(char *format, int *nb)
{
	int result;

	result = 0;
	while (*format >= '0' && *format <= '9')
	{
		result = result * 10 + *format++ - 48;
		if (result < 0)
			break ;
	}
	*nb = result < 0 ? 0 : result;
	return ((char *)format - 1);
}

int			base_len(uintmax_t nb, int base)
{
	int len;

	len = 1;
	while (nb /= base)
		len++;
	return (len);
}

intmax_t	get_signed(va_list args, t_flag *flags)
{
	intmax_t nb;

	if (flags->j)
		nb = va_arg(args, intmax_t);
	else if (flags->z)
		nb = va_arg(args, ssize_t);
	else if (flags->l)
		nb = flags->l == 1 ? va_arg(args, long) : va_arg(args, long long);
	else if (flags->h)
	{
		nb = flags->h == 1 ? (short)va_arg(args, int)
			: (char)va_arg(args, int);
	}
	else
		nb = va_arg(args, int);
	return (nb);
}

uintmax_t	get_unsigned(va_list args, t_flag *flags)
{
	uintmax_t nb;

	if (flags->j)
		nb = va_arg(args, uintmax_t);
	else if (flags->z)
		nb = va_arg(args, size_t);
	else if (flags->l)
	{
		nb = flags->l == 1 ? va_arg(args, unsigned long)
			: va_arg(args, unsigned long long);
	}
	else if (flags->h)
	{
		nb = flags->h == 1 ? (unsigned short)va_arg(args, unsigned)
			: (unsigned char)va_arg(args, unsigned);
	}
	else
		nb = va_arg(args, unsigned);
	return (nb);
}

char		*get_bg(char *col, char *seq)
{
	if ((col = ft_strchr(col, ':')) && !ft_strcmp(col, ":bg}"))
		if ((col = ft_strchr(seq, '3')))
			++(*col);
	return (seq);
}

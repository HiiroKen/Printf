/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorra <fmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:25:05 by fmorra            #+#    #+#             */
/*   Updated: 2024/05/17 13:25:06 by fmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

static int	put_x(char s, long long nb)
{
	int	total;

	total = 0;
	if (s == 'x')
		total = ft_putnbr_hexa(nb, "0123456789abcdef");
	if (s == 'X')
		total = ft_putnbr_hexa(nb, "0123456789ABCDEF");
	return (total);
}

static int	put_p(unsigned long p)
{
	if (!p)
		return (ft_putstr("(nil)"));
	else
		return (ft_putstr("0x") + ft_putnbr_hexa(p, "0123456789abcdef"));
}

static char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

int	know_type(const char *s, va_list ap)
{
	int	total;

	total = 0;
	while (*s)
	{
		if (*s == '%' && ft_strchr("cspdiuxX%", *(s + 1)))
		{
			s++;
			if (*s == 'c')
				total += (ft_putchar(va_arg(ap, int)));
			else if (*s == 's')
				total += (ft_putstr(va_arg(ap, char *)));
			else if (*s == 'p')
				total += (put_p(va_arg(ap, unsigned long)));
			else if (*s == 'd' || *s == 'i')
				total += (ft_putnbr(va_arg(ap, int)));
			else if (*s == 'u')
				total += (ft_putnbr_u(va_arg(ap, unsigned int)));
			else if (*s == 'x' || *s == 'X')
				total += (put_x(*s, va_arg(ap, unsigned int)));
			else if (*s == '%')
				total += (ft_putchar('%'));
		}
		else
			total += (ft_putchar(*s));
		s++;
	}
	return (total);
}

int	ft_printf(const char *s, ...)
{
	int		total;
	va_list	ap;

	total = 0;
	va_start(ap, s);
	total += know_type(s, ap);
	va_end(ap);
	return (total);
}

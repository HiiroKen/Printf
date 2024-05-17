/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:56:58 by fmorra            #+#    #+#             */
/*   Updated: 2024/05/17 13:12:44 by fmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	know_type(const char *s, va_list ap);

int	ft_putchar(char c);
int	ft_putstr(char *c);
int	ft_putnbr_hexa(unsigned long long nb, char *base);
int	ft_putnbr(long long nb);
int	ft_putnbr_u(unsigned int nb);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:40:41 by szine-            #+#    #+#             */
/*   Updated: 2024/10/11 18:45:25 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_the(char z, va_list pf)
{
	int	len;

	len = 0;
	if (z == 'c')
		len = ft_putchar(va_arg(pf, int));
	else if (z == 's')
		len = ft_putstr(va_arg(pf, char *));
	else if (z == 'u')
		len = ft_putu(va_arg(pf, unsigned int));
	else if (z == 'd' || z == 'i')
		len = putnlen(va_arg(pf, int));
	else if (z == 'x')
		len = putnbrlen(va_arg(pf, unsigned int), 'x');
	else if (z == 'X')
		len = putnbrlen(va_arg(pf, unsigned int), 'X');
	else if (z == 'p')
	{
		write(1, "0x", 2);
		len = (putnbrlen((va_arg(pf, unsigned long)), 'x') + 2);
	}
	else if (z == '%')
	{
		len += write(1, "%", 1);
	}
	return (len);
}

int	eprintf(const char *format, ...)
{
	va_list	pf;
	int		count;

	count = 0;
	va_start(pf, format);
	while (*format != '\0')
	{
		if (*format == '%')
			count += print_the(*(++format), pf);
		else
			count += write(2, format, 1);
		format++;
	}
	va_end(pf);
	return (count);
}

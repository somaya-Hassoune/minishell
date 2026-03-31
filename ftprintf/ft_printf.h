/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:21:21 by szine-            #+#    #+#             */
/*   Updated: 2024/10/11 18:45:05 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	eprintf(const char *format, ...);
int	ft_putchar(char c);
int	putnbrlen(unsigned long nbr, char c);
int	putnlen(int nbr);
int	ft_putstr(char *s);
int	ft_putu(unsigned int nbr);

#endif

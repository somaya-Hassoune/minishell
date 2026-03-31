/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:39:26 by szine-            #+#    #+#             */
/*   Updated: 2024/10/11 18:45:45 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base(unsigned long long nbr, char c, int *i)
{
	char	*s;

	if (c == 'x')
		s = "0123456789abcdef";
	if (c == 'X')
		s = "0123456789ABCDEF";
	if (nbr < 16)
	{
		write(2, &s[nbr], 1);
		(*i)++;
	}
	else
	{
		ft_putnbr_base(nbr / 16, c, i);
		write(2, &s[nbr % 16], 1);
		(*i)++;
	}
}

int	putnbrlen(unsigned long nbr, char c)
{
	int	i;

	i = 0;
	ft_putnbr_base(nbr, c, &i);
	return (i);
}

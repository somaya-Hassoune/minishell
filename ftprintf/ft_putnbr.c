/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:26:20 by szine-            #+#    #+#             */
/*   Updated: 2024/10/11 18:45:57 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(long nbr, int *i)
{
	if (nbr < 0)
	{
		write(2, "-", 1);
		(*i)++;
		ft_putnbr(-nbr, i);
	}
	else if (nbr <= 9)
	{
		nbr = nbr + 48;
		write(2, &nbr, 1);
		(*i)++;
	}
	else
	{
		ft_putnbr(nbr / 10, i);
		nbr = nbr % 10 + 48;
		write(2, &nbr, 1);
		(*i)++;
	}
}

int	putnlen(int nbr)
{
	int	i;

	i = 0;
	ft_putnbr(nbr, &i);
	return (i);
}

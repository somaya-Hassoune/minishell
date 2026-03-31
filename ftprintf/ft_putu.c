/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:29:12 by szine-            #+#    #+#             */
/*   Updated: 2024/10/11 18:46:18 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putpositive(unsigned int nbr, int *i)
{
	if (nbr <= 9)
	{
		nbr = nbr + 48;
		write(2, &nbr, 1);
		(*i)++;
	}
	else
	{
		ft_putpositive(nbr / 10, i);
		nbr = nbr % 10 + 48;
		write(2, &nbr, 1);
		(*i)++;
	}
}

int	ft_putu(unsigned int nbr)
{
	int	i;

	i = 0;
	ft_putpositive(nbr, &i);
	return (i);
}

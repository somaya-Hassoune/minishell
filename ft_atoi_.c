/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:51:46 by szine-            #+#    #+#             */
/*   Updated: 2024/12/27 08:57:44 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

long	ft_atoi_(char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if ((str[i] == '+' && str[i + 1]) || (str[i] == '-' && str[i + 1]))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		if (res > INT_MAX || res < INT_MIN)
			return (2200000000);
		i++;
	}
	while ((str[i] && str[i] == ' '))
		i++;
	if (str[i] != '\0')
		return (2200000000);
	return (res * sign);
}

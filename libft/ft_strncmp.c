/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:45:49 by szine-            #+#    #+#             */
/*   Updated: 2023/11/30 15:44:12 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *x, const char *y, size_t n)
{
	size_t	i;

	i = 0;
	while (x[i] && y[i] && i < n)
	{
		if (x[i] != y[i])
			return ((unsigned char)x[i] - (unsigned char)y[i]);
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	else if (x[i] == '\0' && y[i] != '\0')
	{
		return (-1);
	}
	else if (x[i] != '\0' && y[i] == '\0')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 00:34:11 by szine-            #+#    #+#             */
/*   Updated: 2024/06/06 10:03:47 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t numelement, size_t elementsize)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = malloc(numelement * elementsize);
	if (str == NULL)
		return (NULL);
	while (i < numelement * elementsize)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

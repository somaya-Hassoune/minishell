/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:28:11 by szine-            #+#    #+#             */
/*   Updated: 2023/11/30 15:28:46 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*d;

	p = (unsigned char *)dest;
	d = (unsigned char *)src;
	i = 0;
	if (p < d)
	{
		while (i < n)
		{
			p[i] = d[i];
			i++;
		}
	}
	if (p > d)
	{
		while (n > 0)
		{
			p[n - 1] = d[n - 1];
			n--;
		}
	}
	return (dest);
}

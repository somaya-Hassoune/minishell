/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:53:54 by szine-            #+#    #+#             */
/*   Updated: 2023/12/03 14:02:32 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	p = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (p == s)
		return (p);
	i = 0;
	while (i < n)
	{
		p[i] = s[i];
		i++;
	}
	return (p);
}

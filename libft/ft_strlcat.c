/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:43:10 by szine-            #+#    #+#             */
/*   Updated: 2023/11/30 15:42:53 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	slen;
	size_t	dlen;
	size_t	j;

	j = 0;
	i = 0;
	if (size == 0 && dst == NULL)
		return (ft_strlen(src));
	while (dst[j])
	{
		j++;
	}
	dlen = j;
	slen = ft_strlen(src);
	if (dlen >= size)
		return (slen + size);
	while (src[i] && i < size - dlen - 1)
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	return (slen + dlen);
}

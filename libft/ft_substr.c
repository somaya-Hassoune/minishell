/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:24:47 by szine-            #+#    #+#             */
/*   Updated: 2023/11/30 18:27:07 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*zeroadd(char *x, int i)
{
	x[i] = '\0';
	return (x);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*x;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen((const char *)s))
	{
		x = (char *)malloc(1 * sizeof(char));
		if (x == NULL)
			return (NULL);
		x[0] = '\0';
		return (x);
	}
	if (len > ft_strlen((const char *)s) - start)
		len = ft_strlen((const char *)s) - start;
	x = (char *)malloc((len + 1) * sizeof(char));
	if (x == NULL)
		return (NULL);
	while (i < len)
	{
		x[i] = s[start + i];
		i++;
	}
	return (zeroadd(x, i));
}

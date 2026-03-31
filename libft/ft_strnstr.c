/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:25:26 by szine-            #+#    #+#             */
/*   Updated: 2023/11/30 18:29:49 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (str == NULL && len == 0)
		return (NULL);
	if (tofind[0] == '\0')
		return ((char *)str);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == tofind[j] && tofind[j] && (i + j) < len)
		{
			j++;
		}
		if (tofind[j] == '\0')
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:47:14 by szine-            #+#    #+#             */
/*   Updated: 2024/11/21 16:03:38 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*x;
	size_t	a;

	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	a = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	x = (char *)malloc((a + 1) * sizeof(char));
	if (x == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		x[i] = s1[i];
		i++;
	}
	while (i < a)
	{
		x[i++] = s2[j++];
	}
	x[i] = '\0';
	return (x);
}

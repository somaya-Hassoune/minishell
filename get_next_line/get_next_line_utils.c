/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 05:03:33 by szine-            #+#    #+#             */
/*   Updated: 2024/07/31 00:01:24 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char **line, char *buff)
{
	size_t	i;
	size_t	j;
	char	*x;
	size_t	a;

	j = 0;
	a = ft_strlen(*line) + ft_strlen(buff);
	i = 0;
	x = (char *)malloc((a + 1) * sizeof(char));
	if (x == NULL)
		return (NULL);
	while (i < ft_strlen(*line))
	{
		x[i] = (*line)[i];
		i++;
	}
	while (i < a)
		x[i++] = buff[j++];
	x[i] = '\0';
	free((void *)*line);
	return (x);
}

char	*ft_strchr(char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (1)
	{
		if (*s == (char)c)
			return ((char *)s);
		if (*s == '\0')
			return (NULL);
		s++;
	}
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

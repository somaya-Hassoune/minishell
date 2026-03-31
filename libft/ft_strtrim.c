/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:27:19 by szine-            #+#    #+#             */
/*   Updated: 2024/06/06 10:04:28 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	strncpyy(char *dest, char const *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[n] = '\0';
}

static void	startend(char const *s1, char const *set, size_t *end, size_t *i)
{
	*i = 0;
	*end = 0;
	while (s1[*i] && ft_strchr(set, s1[*i]) != (void *)0)
	{
		(*i)++;
	}
	*end = ft_strlen(s1) - 1;
	while ((*end) > (*i) && ft_strchr(set, s1[*end]) != (void *)0)
	{
		(*end)--;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	end;
	char	*emptystr;
	char	*result;

	if (s1 == NULL || set == NULL)
	{
		return (NULL);
	}
	startend(s1, set, &end, &i);
	if (s1[i] == '\0')
	{
		emptystr = (char *)malloc(1 * sizeof(char));
		if (!emptystr)
			return (NULL);
		emptystr[0] = '\0';
		return (emptystr);
	}
	result = (char *)malloc((end - i + 2) * sizeof(char));
	if (result == NULL)
		return (NULL);
	strncpyy(result, s1 + i, end - i + 1);
	return (result);
}

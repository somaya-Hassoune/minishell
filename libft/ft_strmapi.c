/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:36:34 by szine-            #+#    #+#             */
/*   Updated: 2023/11/30 17:59:17 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*p;

	i = 0;
	if (!s || !f)
		return (NULL);
	p = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (i < ft_strlen((const char *)s))
	{
		p[i] = (f)(i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}

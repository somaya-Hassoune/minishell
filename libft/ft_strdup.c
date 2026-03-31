/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:58:06 by szine-            #+#    #+#             */
/*   Updated: 2023/11/29 17:29:23 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	size_t	a;
	char	*d;

	i = 0;
	a = 0;
	while (str[i])
	{
		i++;
	}
	d = (char *)malloc((i + 1) * sizeof(char));
	if (d == NULL)
		return (NULL);
	while (str[a])
	{
		d[a] = str[a];
		a++;
	}
	d[a] = '\0';
	return (d);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:02:25 by szine-            #+#    #+#             */
/*   Updated: 2024/09/30 15:54:21 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countn(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		n = -n;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

static void	strnc(char *dest, char const *src, int n)
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

static char	*lescas(int n)
{
	char	*r;

	if (n == 0)
	{
		r = (char *)malloc(2);
		if (!r)
			return (NULL);
		r[0] = '0';
		r[1] = '\0';
	}
	if (n == -2147483648)
	{
		r = (char *)malloc(12 * sizeof(char));
		if (r == NULL)
			return (NULL);
		strnc(r, "-2147483648", 11);
	}
	return (r);
}

static void	banfunction(int *n, int *l)
{
	if (*n < 0)
	{
		*n = (*n) * (-1);
		*l = 1;
	}
}

char	*ft_itoa(int n)
{
	int		b;
	int		l;
	int		k;
	char	*r;

	if (n == 0 || n == -2147483648)
		return (lescas(n));
	b = countn(n);
	k = b;
	l = 0;
	banfunction(&n, &l);
	r = (char *)malloc((countn(n) + l + 1) * sizeof(char));
	if (r == NULL)
		return (NULL);
	while (b >= 1)
	{
		r[b - 1 + l] = (char)(n % 10 + '0');
		n = n / 10;
		b--;
	}
	if (l == 1)
		r[0] = '-';
	r[k + l] = '\0';
	return (r);
}

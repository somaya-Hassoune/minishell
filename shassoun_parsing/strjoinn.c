/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoinn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:33:25 by shassoun          #+#    #+#             */
/*   Updated: 2024/12/27 07:08:23 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin1(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*x;
	size_t	a;

	j = 0;
	if (s1 == NULL)
		return (NULL);
	if (s2 == NULL)
		return (ft_strdup(s1));
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
		x[i++] = s2[j++];
	x[i] = '\0';
	return (x);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*x;
	size_t	a;

	j = 0;
	if (s1 == NULL)
		return (NULL);
	if (s2 == NULL)
		return (s1);
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
		x[i++] = s2[j++];
	x[i] = '\0';
	return (free(s1), free(s2), x);
}

char	*strjoine(char *str1, char *str2, char *str3)
{
	char	*btwo;
	char	*btree;

	if (str2 == NULL)
		return (ft_strjoin1(str1, str3));
	btwo = ft_strjoin1(str1, str2);
	btree = ft_strjoin1(btwo, str3);
	if (str2 != NULL)
		free(btwo);
	return (btree);
}

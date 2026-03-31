/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncp_yy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:40:42 by shassoun          #+#    #+#             */
/*   Updated: 2024/12/26 18:07:53 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*strncp_yy(char *src, int n)
{
	int		i;
	char	*dest;

	dest = malloc(n + 1);
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[n] = '\0';
	return (dest);
}

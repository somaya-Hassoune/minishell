/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_exist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:08:35 by szine-            #+#    #+#             */
/*   Updated: 2024/12/27 05:32:54 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*is_exist(void)
{
	int		x;
	char	*str;

	x = 1;
	while (x < INT_MAX)
	{
		str = ft_itoa(x);
		if (access(str, F_OK) != 0)
			return (str);
		else
			free(str);
		x++;
	}
	return (NULL);
}

void	not_exec(char *str)
{
	int		i;
	char	fl[4096];

	i = 0;
	fl[0] = '.';
	fl[1] = '/';
	while (str[i])
	{
		fl[i + 2] = str[i];
		i++;
	}
	fl[i + 2] = '\0';
	if (access(fl, F_OK) == 0 && access(fl, X_OK) != 0)
	{
		eprintf("bash: %s: Permission denied\n", str);
		exit(126);
	}
}

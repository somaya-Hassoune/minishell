/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntaxe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:46:03 by shassoun          #+#    #+#             */
/*   Updated: 2024/12/26 17:54:12 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	remove_quotes(char *dest, char *src, int len)
{
	ft_memmove(dest, src, len);
}

void	___set(int *flag, int value_flag, int *l, int add_to_l)
{
	*flag = value_flag;
	*l += add_to_l;
}

int	handel_quot(char c, int *flag, int *l)
{
	if (c == '\"' && *flag == 0)
		___set(flag, 1, l, 1);
	else if (c == '\"' && *flag == 1)
		___set(flag, 0, l, -1);
	else if (c == '\'' && *flag == 0)
		___set(flag, 2, l, 1);
	else if (c == '\'' && *flag == 2)
		___set(flag, 0, l, -1);
	else
		return (0);
	return (1);
}

int	pair_qot(char *str)
{
	int	i;
	int	l;
	int	flag;
	int	len;

	i = 0;
	l = 0;
	flag = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if (handel_quot(str[i], &flag, &l) == 1)
		{
			remove_quotes(str + i, str + i + 1, len - i);
			len--;
		}
		else
			i++;
	}
	if (l == 1)
		eprintf("you have an open quote that not closed\n");
	return (l);
}

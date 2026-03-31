/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:36:28 by shassoun          #+#    #+#             */
/*   Updated: 2024/12/26 18:06:06 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	__is__(char *command, int i, char *c, int *flag)
{
	if (command[i] == '\"')
	{
		if (*c == '\"')
			*c = (char)0;
		else
			*c = '\"';
	}
	if (command[i] == '\'')
	{
		if (*flag == 0)
			*flag = 1;
		else
			*flag = 0;
	}
}

int	is_special(char c)
{
	int	a;

	a = (int)c;
	if ((a >= 32 && a <= 47) || (a >= 58 && a <= 64) || (a >= 91 && a <= 96)
		|| (a >= 123 && a <= 126))
	{
		return (1);
	}
	return (0);
}

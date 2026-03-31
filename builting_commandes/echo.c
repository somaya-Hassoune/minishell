/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:15:43 by szine-            #+#    #+#             */
/*   Updated: 2024/12/27 04:30:05 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	detect_flag(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 1;
	if (!str[0] || (str[0] && str[0] != '-') || (str[0] == '-'
			&& str[1] != 'n'))
		return (0);
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	ft_echo(t_redi *command, int *status)
{
	t_redi	*temp;
	int		flag;

	temp = command->next;
	flag = 0;
	while (temp && detect_flag(temp->file) == 1)
	{
		temp = temp->next;
	}
	if (temp != command->next)
	{
		flag = 1;
	}
	while (temp)
	{
		printf("%s", temp->file);
		temp = temp->next;
		if (temp)
			printf(" ");
	}
	if (flag == 0)
	{
		printf("\n");
	}
	*status = 0;
}

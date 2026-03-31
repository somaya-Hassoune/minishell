/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 05:52:29 by szine-            #+#    #+#             */
/*   Updated: 2024/12/28 11:08:52 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	len_of_all(t_pipe *all)
{
	int	count;

	count = 0;
	while (all)
	{
		count++;
		all = all->next;
	}
	return (count);
}

int	ft_is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	___chkst(t_redi **temp, t_redi **output)
{
	*temp = *output;
	if (*output == NULL)
		return (1);
	return (0);
}

int	for_in(t_redi *temp)
{
	int	fd;

	fd = -1;
	if (temp->mode == '>')
		fd = open(temp->file, O_WRONLY | O_TRUNC | O_CREAT, 0666);
	else
		fd = open(temp->file, O_WRONLY | O_APPEND | O_CREAT, 0666);
	if (fd == -1)
		return (eprintf("bash : %s ", temp->file), perror(""), -1);
	dup2(fd, 1);
	return (fd);
}

void	inisialize_tab(int *tab)
{
	int	i;

	i = 0;
	while (i < 1024)
	{
		tab[i] = 0;
		i++;
	}
}

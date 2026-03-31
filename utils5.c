/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 05:59:01 by szine-            #+#    #+#             */
/*   Updated: 2024/12/28 11:09:03 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**convert(t_redi *command)
{
	t_redi	*temp;
	int		i;
	char	**str;
	int		flag;

	i = 0;
	flag = 0;
	temp = command;
	str = NULL;
	is_empty(command);
	while (temp)
	{
		if ((count_words(temp->file, ' ') > 1) && (temp->is_the == 42))
			i += count_words(temp->file, ' ');
		else
			i++;
		temp = temp->next;
	}
	temp = command;
	str = malloc(sizeof(char *) * (i + 1));
	return (get_itt(temp, str));
}

int	check_build(t_pipe *current, int *tab, t_redi *env, int *status)
{
	int	a;
	int	b;

	a = 0;
	if (current->next == NULL && is_building(current, env) == 1)
	{
		dup2(1, 1021);
		dup2(0, 1020);
		a = dup_the_out(current->output);
		b = dup_the_in(current->input, tab[0]);
		build_in(current, env, status, 1);
		if (a > 0)
			dup2(1021, 1);
		if (b > 0)
			dup2(1020, 0);
		close(1020);
		close(1021);
		freetpipe(current);
		return (1);
	}
	return (0);
}

void	close_2(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}

void	if_exit(int a)
{
	if (a == -1)
		exit(1);
}

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 05:48:20 by szine-            #+#    #+#             */
/*   Updated: 2024/12/28 10:33:40 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	first_command(t_pipe *current, int *fd, int *old_end, int nameHerdocfile)
{
	int	k;
	int	g;

	k = 0;
	g = 0;
	if (current->output == NULL && current->next != NULL)
		dup2(fd[1], STDOUT_FILENO);
	else
		g = dup_the_out(current->output);
	k = dup_the_in(current->input, nameHerdocfile);
	close(fd[0]);
	close(fd[1]);
	close(old_end[0]);
	close(old_end[1]);
	if (k == -1 || g == -1)
		return (-1);
	return (0);
}

int	middle_command(t_pipe *current, int *fd, int *old_end, int nameHerdocfile)
{
	int	k;
	int	g;

	k = 0;
	g = 0;
	if (current->input == NULL)
		dup2(old_end[0], STDIN_FILENO);
	else
		k = dup_the_in(current->input, nameHerdocfile);
	if (current->output == NULL)
		dup2(fd[1], STDOUT_FILENO);
	else
		g = dup_the_out(current->output);
	close(fd[0]);
	close(fd[1]);
	close(old_end[0]);
	close(old_end[1]);
	if (k == -1 || g == -1)
		return (-1);
	return (0);
}

int	last_command(t_pipe *current, int *fd, int *old_end, int nameHerdocfile)
{
	int	k;
	int	g;

	k = 0;
	g = 0;
	if (current->input == NULL)
	{
		dup2(old_end[0], STDIN_FILENO);
	}
	else
	{
		k = dup_the_in(current->input, nameHerdocfile);
	}
	g = dup_the_out(current->output);
	close(fd[0]);
	close(fd[1]);
	close(old_end[0]);
	close(old_end[1]);
	if (k == -1 || g == -1)
		return (-1);
	return (0);
}

void	wait_and_set(int *status, int pid)
{
	int	k;
	int	s;

	k = 0;
	s = 0;
	while (1)
	{
		k = wait(&s);
		if (k == pid)
		{
			*status = WEXITSTATUS(s);
			if (s == 131)
			{
				*status = 131;
				write(1, "\n", 1);
			}
			else if (s == 2)
				*status = 130;
		}
		else if (k < 0)
			break ;
	}
}

void	delete_herr_fil(int *tab)
{
	int		index;
	char	*to_del;

	index = 0;
	to_del = NULL;
	while (tab[index] > 0)
	{
		to_del = ft_strjoin2(ft_strdup("/tmp/"), ft_itoa(tab[index]));
		unlink(to_del);
		index++;
		free(to_del);
	}
}

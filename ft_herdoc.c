/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_herdoc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 05:24:55 by szine-            #+#    #+#             */
/*   Updated: 2024/12/28 10:56:23 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	put_that(t_redi *env, int *status, char *the_input, int fd)
{
	int	i;

	i = 0;
	if (ft_strchr(the_input, '$') != NULL && env != NULL)
		the_input = ft_expand(the_input, status, env);
	while ((the_input[i]) && (the_input[i] != '\n'))
	{
		write(fd, &the_input[i], 1);
		i++;
	}
	if (the_input)
		write(fd, "\n", 1);
	free(the_input);
}

int	is_the_limit(char *limit, char *the_input)
{
	int	i;

	i = 0;
	while (the_input && limit && limit[i] && the_input[i]
		&& limit[i] == the_input[i])
	{
		i++;
	}
	if (!limit[i] && the_input[i] && the_input[i] == '\n')
	{
		free(the_input);
		return (1);
	}
	return (0);
}

int	child_herr(char *limit, t_redi *env, int *status, char *name_of_file)
{
	char	*the_input;
	int		fd;

	the_input = NULL;
	fd = -1;
	fd = open(name_of_file, O_CREAT | O_WRONLY, 0777);
	signal(SIGINT, handherr);
	while (1)
	{
		write(1, ">", 1);
		the_input = get_next_line(0);
		if (is_the_limit(limit, the_input) == 1)
			break ;
		if (chk_ctrld(the_input, name_of_file) == 1)
			return (-1);
		put_that(env, status, the_input, fd);
	}
	return (fd);
}

int	put_in_file(char *limit, t_redi *env, int *status, int is_last)
{
	char	*name_of_file;
	int		fd;
	int		x;
	int		st;

	name_of_file = is_exist();
	x = ft_atoi(name_of_file);
	name_of_file = ft_strjoin2(ft_strdup("/tmp/"), name_of_file);
	if (fork() == 0)
	{
		fd = child_herr(limit, env, status, name_of_file);
		if (is_last == 0)
			return (if_last(name_of_file), close(fd), exit(0), 1);
		return (free(name_of_file), close(fd), exit(0), 1);
	}
	else
	{
		free(name_of_file);
		wait(&st);
		st = WEXITSTATUS(st);
		if (st == 130)
			return (-2);
	}
	return (x);
}

int	ft_herdoc(int *tab, t_pipe *all, t_redi *env, int *status)
{
	t_redi	*temp;
	int		i;
	int		k;

	if (!all->input)
		return (0);
	_set0(&i, &k);
	while (all)
	{
		tab[i] = -1;
		temp = all->input;
		while (temp != NULL)
		{
			if (one_herdoc(&tab[i], temp, env, status) == 1)
				return (1);
			temp = temp->next;
		}
		i++;
		all = all->next;
	}
	return (0);
}

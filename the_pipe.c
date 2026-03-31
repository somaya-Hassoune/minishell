/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:39:43 by szine-            #+#    #+#             */
/*   Updated: 2024/12/28 11:10:58 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	in_the_child2(t_pipe *current, t_redi *env, int *status)
{
	char	**arg;
	char	**envp;
	char	*path;
	int		i;

	i = 0;
	arg = NULL;
	envp = NULL;
	path = NULL;
	if (build_in(current, env, status, 0) == 1)
		exit(*status);
	arg = convert(current->commd);
	envp = convert(env);
	path = find_path(&(t_redi){arg[0], 0, 0, NULL}, env);
	execve(path, arg, envp);
	free_dbl(arg);
	free_dbl(envp);
	exit(2);
}

void	child_handler(int sig)
{
	(void)sig;
	exit(130);
}

void	_command(t_tt *tt, int *fd, int *old_end, int herr)
{
	int	a;

	a = 0;
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, child_handler);
	if (tt->current == tt->all)
		a = first_command(tt->current, fd, old_end, herr);
	else if (tt->current->next == NULL)
		a = last_command(tt->current, fd, old_end, herr);
	else
		a = middle_command(tt->current, fd, old_end, herr);
	if_exit(a);
}

int	generat_childs(t_tt *tt, int *tab, int *status)
{
	int	index;
	int	old_end[2];
	int	fd[2];
	int	id;

	index = -1;
	pipe(fd);
	while (tt->current)
	{
		fd_old_new(old_end, fd, &index);
		signal(SIGQUIT, SIG_IGN);
		id = fork();
		tt->pid = id;
		if (id == 0)
		{
			_command(tt, fd, old_end, tab[index]);
			in_the_child2(tt->current, tt->env, status);
		}
		close_2(old_end[0], old_end[1]);
		tt->current = tt->current->next;
	}
	return (wait_and_set(status, tt->pid), close_2(fd[0], fd[1]), 0);
}

int	the_pipe(char *str, int *status, t_redi *env)
{
	t_pipe	*all;
	int		tab[1024];
	t_pipe	*current;
	t_tt	tt;

	inisialize_tab(tab);
	all = uusplit(str, status, env);
	if (all == NULL)
		return (0);
	if (ft_herdoc(tab, all, env, status))
	{
		return (delete_herr_fil(tab), freetpipe(all), 0);
	}
	current = all;
	tt.all = all;
	tt.current = current;
	tt.env = env;
	if (check_build(current, tab, env, status) == 1)
		return (0);
	generat_childs(&tt, tab, status);
	delete_herr_fil(tab);
	freetpipe(all);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeTpipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 02:01:18 by szine-            #+#    #+#             */
/*   Updated: 2024/12/27 05:23:02 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	freetpipe(t_pipe *all)
{
	t_pipe	*previous;

	previous = all;
	while (previous)
	{
		all = previous->next;
		free_liste(previous->input);
		free_liste(previous->output);
		free_liste(previous->commd);
		free(previous);
		previous = all;
	}
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

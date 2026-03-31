/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 05:44:27 by szine-            #+#    #+#             */
/*   Updated: 2024/12/28 11:12:47 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redi	*new_node(char *str, int flag)
{
	t_redi	*redi;

	redi = malloc(sizeof(t_redi));
	redi->file = str;
	redi->mode = flag;
	redi->next = NULL;
	return (redi);
}

void	add_node(t_redi **list, t_redi *node)
{
	t_redi	*temp;

	temp = *list;
	if (!list || !*list)
	{
		*list = node;
		return ;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = node;
}

void	_set0(int *i, int *k)
{
	*i = 0;
	*k = 0;
}

void	fd_old_new(int *old_end, int *fd, int *index)
{
	old_end[1] = fd[1];
	old_end[0] = fd[0];
	pipe(fd);
	(*index)++;
}

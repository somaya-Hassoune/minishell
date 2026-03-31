/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:23:50 by shassoun          #+#    #+#             */
/*   Updated: 2024/12/26 18:31:27 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_liste(t_redi *li)
{
	t_redi	*temp;

	temp = li;
	while (li)
	{
		temp = li;
		free(li->file);
		li = li->next;
		free(temp);
	}
}

int	check_quot(int fg, t_redi **tocken, int *status)
{
	if (fg == 1)
	{
		*status = 2;
		free_liste(*tocken);
		eprintf("syntaxe error open quote\n");
		return (1);
	}
	return (0);
}

void	__check_set(char *command, char *c, int k, int *fg)
{
	*c = command[k];
	*fg = 1;
}

int	many_herdoc(t_redi *tocken)
{
	t_redi	*temp;
	int		count;

	temp = tocken;
	count = 0;
	while (temp)
	{
		if (temp->mode == '<' + 1)
			count++;
		temp = temp->next;
	}
	if (count >= 16)
	{
		eprintf("%s\n", "bash: maximum here-document count exceeded\n");
		return (1);
	}
	return (0);
}

void	check_herdoc(t_redi *nty, int *fg)
{
	pair_qot(nty->file);
	if (nty->mode == '<' + 1)
		*fg = 1;
}

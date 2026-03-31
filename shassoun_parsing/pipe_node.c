/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:19:41 by shassoun          #+#    #+#             */
/*   Updated: 2024/12/26 20:04:37 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	detach_set(t_redi **so, t_redi **temp, t_redi **list)
{
	(*so) = (*temp)->next;
	(*so)->mode = (*temp)->mode;
	free((*temp)->file);
	free(*temp);
	*temp = (*so)->next;
	(*so)->next = NULL;
	add_node(list, (*so));
}

void	new_pipe_node(t_redi **temp, t_pipe *pr)
{
	t_redi	*so;

	so = NULL;
	if ((*temp && (*temp)->mode == '<') || ((*temp)->mode == '<' + 1))
	{
		detach_set(&so, temp, &pr->input);
	}
	else if ((*temp && (*temp)->mode == '>') || ((*temp)->mode == '>' + 1))
	{
		detach_set(&so, temp, &pr->output);
	}
	else if (*temp && (*temp)->mode == 0)
	{
		so = *temp;
		*temp = (*temp)->next;
		so->next = NULL;
		add_node(&pr->commd, so);
	}
}

void	add_pipe_node(t_pipe **all, t_pipe *pr, t_redi **temp)
{
	t_pipe	*temp1;
	t_redi	*so;

	temp1 = NULL;
	so = NULL;
	if (*all == NULL)
		*all = pr;
	else
	{
		temp1 = *all;
		while (temp1->next)
			temp1 = temp1->next;
		temp1->next = pr;
	}
	if (*temp && (*temp)->mode == '|')
	{
		so = *temp;
		*temp = (*temp)->next;
		free(so->file);
		free(so);
	}
}

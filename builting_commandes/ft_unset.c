/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 04:39:48 by szine-            #+#    #+#             */
/*   Updated: 2024/12/27 04:42:20 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	remove_node(t_redi *toRemove, t_redi *previous)
{
	previous->next = toRemove->next;
	free(toRemove->file);
	free(toRemove);
}

void	__help(t_redi **env, t_redi *to_remove)
{
	(*env) = (*env)->next;
	free(to_remove->file);
	free(to_remove);
}

void	unset_one(t_redi **env, char *str)
{
	int		i;
	t_redi	*to_remove;
	t_redi	*previous;

	to_remove = *env;
	previous = NULL;
	i = 0;
	while (to_remove)
	{
		i = 0;
		while (to_remove->file[i] && str[i] && to_remove->file[i] == str[i])
			i++;
		if ((str[i] == '\0' && (to_remove->file[i] == '='
					|| to_remove->file[i] == '\0')))
		{
			if (to_remove != *env)
				remove_node(to_remove, previous);
			else
				__help(env, to_remove);
			break ;
		}
		previous = to_remove;
		to_remove = to_remove->next;
	}
}

void	unset(t_redi **env, t_redi *command, int *status)
{
	*status = 0;
	while (command)
	{
		unset_one(&((*env)->next), command->file);
		command = command->next;
	}
}

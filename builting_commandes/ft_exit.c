/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 00:16:25 by szine-            #+#    #+#             */
/*   Updated: 2024/12/28 09:35:00 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exitt(t_pipe *all, t_redi *env, int k)
{
	freetpipe(all);
	free_liste(env);
	if (k >= 0)
		exit(k % 256);
	else
		exit(256 + k);
}

void	__help1(t_pipe *all, t_redi *env, int *status)
{
	rl_clear_history();
	eprintf("exit\n");
	if (all->commd->next == NULL)
	{
		close(1020);
		close(1021);
		if (all->commd->next == NULL)
			exitt(all, env, *status);
	}
}

int	ft_exit(t_pipe *all, int *status, t_redi *env)
{
	int	k;

	k = 0;
	__help1(all, env, status);
	if (all->commd->next != NULL)
	{
		if ((all->commd->next->file
				&& ft_atoi_(all->commd->next->file) == 2200000000)
			|| (all->commd->next->file)[0] == '\0')
		{
			eprintf("bash: exit: %s: numeric argument required\n",
				all->commd->next->file);
			exitt(all, env, 2);
		}
		else if (all->commd->next->next != NULL)
			return (eprintf("bash: exit: too many arguments\n"), exitt(all, env,
					1), 0);
		else
		{
			k = ft_atoi_(all->commd->next->file);
			exitt(all, env, k);
		}
	}
	return (0);
}

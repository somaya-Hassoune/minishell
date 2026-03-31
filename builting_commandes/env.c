/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 04:40:12 by szine-            #+#    #+#             */
/*   Updated: 2024/12/27 04:40:16 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(t_redi *env, int *status)
{
	env = env->next;
	while (env)
	{
		if (env->mode == 1)
			printf("%s\n", env->file);
		env = env->next;
	}
	printf("%s\n", "_=/usr/bin/env");
	*status = 0;
}

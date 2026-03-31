/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 05:34:09 by szine-            #+#    #+#             */
/*   Updated: 2024/12/28 11:12:20 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_status = 0;

void	__free_exit(char *sal, t_redi *env, int status)
{
	rl_clear_history();
	eprintf("exit\n");
	free(sal);
	free_liste(env);
	exit(status);
}

int	main(void)
{
	char	*sal;
	char	*tri;
	t_redi	*env;
	int		*status;

	rl_catch_signals = 0;
	status = &g_status;
	env = gettheenv();
	signal(SIGQUIT, handle_sigquit);
	while (1)
	{
		signal(SIGINT, handle_sigint);
		sal = readline("minishell >$ ");
		signal(SIGINT, handle_sigint2);
		if (sal == NULL)
			__free_exit(sal, env, g_status);
		if (sal && sal[0] != '\0')
		{
			tri = ft_strtrim(sal, " \t\n\v\f\r");
			if (tri && tri[0] != '\0')
				add_history(sal);
			free(tri);
			the_pipe(sal, &g_status, env);
		}
	}
}

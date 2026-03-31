/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 05:31:33 by szine-            #+#    #+#             */
/*   Updated: 2024/12/28 11:08:29 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_directory(char *path)
{
	struct stat	path_;

	if (path && path[0] != '\0' && stat(path, &path_) == 0)
	{
		return (S_ISDIR(path_.st_mode));
	}
	return (0);
}

int	chk_ctrld(char *the_input, char *name_of_file)
{
	if (!the_input)
	{
		free(name_of_file);
		printf("Minishell: EOF\n");
		exit(0);
	}
	return (0);
}

int	if_last(char *name_of_file)
{
	unlink(name_of_file);
	free(name_of_file);
	return (-1);
}

int	is_that_shlvl(char *envi)
{
	int		i;
	char	*str;

	i = 0;
	str = "SHLVL=";
	while (envi[i] && str[i] && envi[i] == str[i])
	{
		i++;
	}
	if (!str[i])
		return (1);
	else
		return (0);
	return (0);
}

t_redi	*gettheenv(void)
{
	extern char	**environ;
	int			i;
	t_redi		*env;
	t_redi		*temp;

	env = NULL;
	temp = NULL;
	i = 0;
	temp = new_node(ft_strdup("LD_LIBRARY_PATH=/home/szine-/.local/lib:"), 1);
	add_node(&env, temp);
	while (environ[i + 1])
	{
		if (is_that_shlvl(env->file) == 1)
			temp = new_node(ft_strjoin2(ft_strdup(environ[i]),
						ft_strdup("    ")), 1);
		else
			temp = new_node(ft_strdup(environ[i]), 1);
		add_node(&env, temp);
		i++;
	}
	return (env);
}

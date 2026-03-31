/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:41:46 by szine-            #+#    #+#             */
/*   Updated: 2024/12/28 09:38:29 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_some(char *path, char **all_paths)
{
	int	i;

	i = 0;
	free(path);
	while (all_paths[i])
	{
		free(all_paths[i]);
		i++;
	}
	free(all_paths);
}

void	check_no(char *str)
{
	if (strchr(str, '/'))
	{
		eprintf("%s %s\n", "no such file or directory:", str);
		exit(127);
	}
	else
	{
		eprintf("%s %s\n", "command not found", str);
		exit(127);
	}
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
	{
		i++;
	}
	if (!str1[i] && !str2[i])
		return (0);
	else
		return (1);
}

char	*go_for(char **all_paths, char *str)
{
	int		i;
	char	*isthepath;

	i = 0;
	isthepath = NULL;
	if (!all_paths)
		return (NULL);
	while (all_paths[i])
	{
		isthepath = ft_strjoin2(all_paths[i], ft_strdup("/"));
		isthepath = ft_strjoin2(isthepath, ft_strdup(str));
		if (access(isthepath, X_OK) == 0)
		{
			break ;
		}
		i++;
		free(isthepath);
	}
	if (all_paths[i])
		return (isthepath);
	return (NULL);
}

char	*find_path(t_redi *command, t_redi *env)
{
	char	*isthepath;
	char	*str;
	char	*path;
	char	**all_paths;

	isthepath = NULL;
	str = command->file;
	not_exec(str);
	if ((str == NULL) || (str[0] == '\0'))
		exit(0);
	if (is_directory(str))
		return (eprintf("bash: %s: Is a directory\n", str), exit(126), NULL);
	if (access(str, X_OK) == 0)
		return (str);
	path = get_from_my_env("PATH", env, '\"');
	all_paths = ft_split(path, ':');
	if (all_paths == NULL)
		return (eprintf("%s %s\n", "no such file or directory:", str),
			exit(126), NULL);
	isthepath = go_for(all_paths, str);
	if (isthepath != NULL && isthepath[0] != '\0')
		return (isthepath);
	check_no(str);
	return (NULL);
}

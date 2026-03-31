/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 21:33:43 by szine-            #+#    #+#             */
/*   Updated: 2024/12/27 04:30:18 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_env(t_redi *env, char *str)
{
	int	i;

	i = 0;
	while (str[i] && env)
	{
		i = 0;
		while ((env->file[i] && str[i] && env->file[i] == str[i]))
		{
			i++;
		}
		if (!str[i] && env->file[i] == '=')
		{
			return (env->file);
		}
		i++;
		env = env->next;
	}
	return (NULL);
}

char	*cd_home(t_redi *command, t_redi *env, int *status)
{
	char	*str;

	if (command->next == NULL)
	{
		str = get_env(env, "HOME");
		if (str == NULL)
		{
			eprintf("bash: cd: HOME not set\n");
			*status = 1;
			return (NULL);
		}
		return (str + 5);
	}
	return (NULL);
}

int	check_error(t_redi *command, int *status)
{
	int	i;

	i = -1;
	*status = 1;
	if (command->next->next != NULL || ft_strchr(command->next->file, ' '))
		return (eprintf("bash: cd: too many arguments\n"), 1);
	else if (access(command->next->file, F_OK) != 0)
	{
		eprintf("bash: cd: %s:", command->next->file);
		perror("");
		return (1);
	}
	else if (access(command->next->file, X_OK) != 0)
	{
		eprintf("bash: cd: %s:", command->next->file);
		perror("");
		return (1);
	}
	*status = 0;
	return (chdir(command->next->file));
}

int	if_h(t_redi *command, t_redi *env, int *status, char *home)
{
	home = cd_home(command, env, status);
	if (home != NULL)
		return (ft_cd_home(command, env, status, home), 1);
	if (command->next == NULL)
		return (1);
	return (0);
}

int	ft_cd(t_redi *command, t_redi *env, int *status)
{
	char	*oldpwd;
	char	*pwd;
	char	*home;

	home = NULL;
	if (if_h(command, env, status, home) == 1)
		return (1);
	oldpwd = malloc(4096);
	pwd = malloc(4096);
	getcwd(oldpwd, 4096);
	oldpwd = ft_strjoin2(ft_strdup("OLDPWD="), oldpwd);
	if (check_error(command, status) == 0)
	{
		export_one(&(t_redi){oldpwd, 0, 0, &(t_redi){oldpwd, 0, 0, NULL}}, env);
		getcwd(pwd, 4096);
		pwd = ft_strjoin2(ft_strdup("PWD="), pwd);
		export_one(&(t_redi){pwd, 0, 0, &(t_redi){pwd, 0, 0, NULL}}, env);
	}
	else
	{
		eprintf("bash: cd: %s:", command->next->file);
		perror("");
		*status = 1;
	}
	return (free(oldpwd), free(pwd), 0);
}

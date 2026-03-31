/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 06:51:04 by szine-            #+#    #+#             */
/*   Updated: 2024/12/29 06:51:09 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_empty(t_redi *tocken)
{
	if ((tocken) && (tocken->next == NULL) && (tocken->file)
		&& (ft_strcmp(tocken->file, "\"\"") == 0 || ft_strcmp(tocken->file,
				"''") == 0))
	{
		tocken->is_the = 13;
	}
}

int	one_herdoc(int *herr, t_redi *temp, t_redi *env, int *status)
{
	int	k;

	k = 0;
	if (temp->mode == '<' + 1)
	{
		if (temp->next == NULL)
			*herr = put_in_file(temp->file, env, status, 1);
		else
			k = put_in_file(temp->file, env, status, 0);
	}
	if (k == -2 || (*herr) == -2)
		return (1);
	return (0);
}

void	is_empty(t_redi *tocken)
{
	if (tocken->is_the == 13)
	{
		eprintf("Command %s not found\n", tocken->file);
		exit(127);
	}
}

int	check_error_home(char *str, int *status)
{
	int	i;

	i = -1;
	*status = 1;
	if (access(str, F_OK) != 0)
	{
		eprintf("bash: cd: %s:", str);
		perror("");
		return (1);
	}
	else if (access(str, X_OK) != 0)
	{
		eprintf("bash: cd: %s:", str);
		perror("");
		return (1);
	}
	*status = 0;
	return (chdir(str));
}

int	ft_cd_home(t_redi *command, t_redi *env, int *status, char *home)
{
	char	*oldpwd;
	char	*pwd;

	(void)command;
	oldpwd = malloc(4096);
	pwd = malloc(4096);
	getcwd(oldpwd, 4096);
	oldpwd = ft_strjoin2(ft_strdup("OLDPWD="), oldpwd);
	*status = 0;
	if (check_error_home(home, status) == 0)
	{
		export_one(&(t_redi){oldpwd, 0, 0, &(t_redi){oldpwd, 0, 0, NULL}}, env);
		getcwd(pwd, 4096);
		pwd = ft_strjoin2(ft_strdup("PWD="), pwd);
		export_one(&(t_redi){pwd, 0, 0, &(t_redi){pwd, 0, 0, NULL}}, env);
	}
	else
	{
		eprintf("bash: cd: %s:", home);
		perror("");
		*status = 1;
	}
	free(oldpwd);
	free(pwd);
	return (0);
}

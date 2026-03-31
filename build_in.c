/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:41:45 by szine-            #+#    #+#             */
/*   Updated: 2024/12/27 05:07:11 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redi	*get_pt_env(t_redi *env, char *str)
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
			return (env);
		}
		i++;
		env = env->next;
	}
	return (NULL);
}

void	incre_shlvl(t_redi *env)
{
	t_redi	*here;
	char	*pt;

	here = get_pt_env(env, "SHLVL");
	if (!here)
		return ;
	pt = here->file;
	if (pt[ft_strlen(pt) - 1] == '9')
	{
		pt[ft_strlen(pt) - 1] = '0';
		return ;
	}
	pt[ft_strlen(pt) - 1] += 1;
}

int	is_building_suite(t_pipe *current, t_redi *env)
{
	(void)env;
	if (ft_strcmp(current->commd->file, "echo") == 0
		|| ft_strcmp(current->commd->file, "/usr/bin/echo") == 0)
		return (1);
	if (ft_strcmp(current->commd->file, "cd") == 0)
		return (1);
	if (ft_strcmp(current->commd->file, "pwd") == 0
		|| ft_strcmp(current->commd->file, "/usr/bin/pwd") == 0)
		return (1);
	if (ft_strcmp(current->commd->file, "exit") == 0)
		return (1);
	return (0);
}

int	is_building(t_pipe *current, t_redi *env)
{
	(void)env;
	if (!(current->commd))
		return (0);
	if (ft_strcmp(current->commd->file, "./minishell") == 0)
	{
		incre_shlvl(env);
		return (0);
	}
	if (ft_strcmp(current->commd->file, "env") == 0
		|| ft_strcmp(current->commd->file, "/usr/bin/env") == 0)
		return (1);
	if (ft_strcmp(current->commd->file, "unset") == 0
		|| ft_strcmp(current->commd->file, "/snap/bin/unset") == 0)
		return (1);
	if (ft_strcmp(current->commd->file, "export") == 0
		|| ft_strcmp(current->commd->file, "/snap/bin/export") == 0)
		return (1);
	if (is_building_suite(current, env) == 1)
		return (1);
	return (0);
}

int	build_in(t_pipe *current, t_redi *env, int *status, int flag)
{
	(void)flag;
	if (!(current->commd))
		return (0);
	if (ft_strcmp(current->commd->file, "env") == 0
		|| ft_strcmp(current->commd->file, "/usr/bin/env") == 0)
		ft_env(env, status);
	else if (ft_strcmp(current->commd->file, "unset") == 0
		|| ft_strcmp(current->commd->file, "/snap/bin/unset") == 0)
		unset(&env, current->commd->next, status);
	else if (ft_strcmp(current->commd->file, "export") == 0
		|| ft_strcmp(current->commd->file, "/snap/bin/export") == 0)
		export(current->commd, env, status);
	else if (ft_strcmp(current->commd->file, "echo") == 0
		|| ft_strcmp(current->commd->file, "/usr/bin/echo") == 0)
		ft_echo(current->commd, status);
	else if (ft_strcmp(current->commd->file, "cd") == 0)
		ft_cd(current->commd, env, status);
	else if (ft_strcmp(current->commd->file, "pwd") == 0
		|| ft_strcmp(current->commd->file, "/usr/bin/pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(current->commd->file, "exit") == 0)
		ft_exit(current, status, env);
	else
		return (0);
	return (1);
}

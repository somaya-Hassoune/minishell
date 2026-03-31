/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:16:17 by szine-            #+#    #+#             */
/*   Updated: 2024/12/28 22:16:20 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handherr(int sig)
{
	(void)sig;
	exit(130);
}

void	ddd(int sig)
{
	(void)sig;
	g_status = 130;
	exit(130);
}

void	handle_sigint2(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	g_status = 130;
}

void	handle_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_status = 130;
}

void	handle_sigquit(int sig)
{
	(void)sig;
	g_status = 131;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:10:30 by thaley            #+#    #+#             */
/*   Updated: 2019/07/03 18:18:59 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		print_env(void)
{
	int		i;

	i = -1;
	while (g_env[++i])
	{
		ft_putstr(g_env[i]);
		write(1, "\n", 1);
	}
}

void		print_with_quotes(char **cmd)
{
	int		i;
	int		j;

	i = -1;
	while (cmd[++i])
	{
		j = -1;
		while (cmd[i][++j])
		{
			if ((j == 0 && (cmd[i][j] == '"' || cmd[i][j] == '\\')) ||
			(cmd[i][j + 1] == '\0' && (cmd[i][j] == '\\' || cmd[i][j] == '"')))
				continue ;
			write(1, &cmd[i][j], 1);
		}
		if (cmd[i + 1])
			write(1, " ", 1);
	}
}

void		print_with_input(char **cmd)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	write(1, "> ", 2);
	tmp = take_input();
	while (cmd[++i])
	{
		j = -1;
		while (cmd[i][++j])
		{
			if ((j == 0 && (cmd[i][j] == '"' || cmd[i][j] == '\\'))
			|| (cmd[i][j + 1] == '\0' && (cmd[i][j] == '\\'
			|| cmd[i][j] == '"')))
				continue ;
			write(1, &cmd[i][j], 1);
		}
		if (cmd[i + 1])
			write(1, " ", 1);
	}
	ft_putstr(tmp);
	free(tmp);
}

void		print_echo(char **cmd, int start, int end, int flag)
{
	int		i;

	i = -1;
	if ((start == 2 || start == 1) && end == 2)
		print_with_input(cmd);
	else if ((start == 2 || start == 1) && end == 1)
		print_with_quotes(cmd);
	else if (start == 1 && end == 1)
		print_with_quotes(cmd);
	else
	{
		while (cmd[++i])
		{
			ft_putstr(cmd[i]);
			if (cmd[i + 1])
				write(1, " ", 1);
		}
	}
	if (!flag)
		write(1, "\n", 1);
}

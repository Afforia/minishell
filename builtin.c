/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:20:43 by thaley            #+#    #+#             */
/*   Updated: 2019/06/27 13:44:48 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	print_echo(char **cmd)
{
	int		start;
	int		finish;
	int		i;

	i = 0;
	while (cmd[++i])
	{
		start = 0;
		finish = ft_strlen(cmd[i]);
		if (cmd[i][0] == '"')
			start++;
		if (cmd[i][finish - 1] == '"')
			finish--;
		while (start < finish)
		{
			write(1, &cmd[i][start], 1);
			start++;
		}
		if (cmd[i + 1])
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}

int		check_builtin(char **cmd)
{
	if (!(ft_strcmp(cmd[0], "echo")))
		print_echo(cmd);
	if (!(ft_strcmp(cmd[0], "exit")))
		exit_shell(cmd, 0);
	if (!(ft_strcmp(cmd[0], "cd")))
		change_dir(cmd + 1);
	if (!(ft_strcmp(cmd[0], "env")))
		print_env();
	if (!(ft_strcmp(cmd[0], "setenv")))
		set_env(cmd + 1);
	if (!(ft_strcmp(cmd[0], "unsetenv")))
		unset_env(cmd + 1);
	if (!(ft_strcmp(cmd[0], "pwd")))
		get_built(cmd);
	if (!(ft_strcmp(cmd[0], "ls")))
		get_built(cmd);
	if (!(ft_strcmp(cmd[0], "clear")))
  		get_built(cmd);
	return (0);
}

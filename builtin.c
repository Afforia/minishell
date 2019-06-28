/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:20:43 by thaley            #+#    #+#             */
/*   Updated: 2019/06/28 21:00:21 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_utility(char **cmd)
{
	if (!(ft_strcmp(cmd[0], "pwd")))
		get_built(cmd, 1);
	else if (!(ft_strcmp(cmd[0], "ls")))
		get_built(cmd, 1);
	else if (!(ft_strcmp(cmd[0], "clear")))
		get_built(cmd, 2);
	else if (!(ft_strcmp(cmd[0], "cp")))
		get_built(cmd, 1);
	else if (!(ft_strcmp(cmd[0], "mkdir")))
		get_built(cmd, 1);
	else if (!(ft_strcmp(cmd[0], "rm")))
		get_built(cmd, 1);
	else
		return (0);
	return (1);
}

int		check_builtin(char **cmd)
{
	if (!(ft_strcmp(cmd[0], "echo")))
		print_echo(cmd + 1);
	else if (!(ft_strcmp(cmd[0], "exit")))
		exit_shell(cmd, 0);
	else if (!(ft_strcmp(cmd[0], "cd")))
		change_dir(cmd + 1);
	else if (!(ft_strcmp(cmd[0], "env")))
		print_env();
	else if (!(ft_strcmp(cmd[0], "setenv")))
		set_env(cmd + 1);
	else if (!(ft_strcmp(cmd[0], "unsetenv")))
		unset_env(cmd + 1);
	else
		return (0);
	return (1);
}

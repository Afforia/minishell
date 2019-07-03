/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:20:43 by thaley            #+#    #+#             */
/*   Updated: 2019/07/03 15:45:59 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		count_dir(int pos)
{
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (g_env[pos][++i])
	{
		if (g_env[pos][i] == ':' || g_env[pos][i + 1] == '\0')
			len++;
	}
	return (len);
}

int		search_cmd(char **path_dir, char *cmd)
{
	int				i;
	DIR				*dir;
	struct dirent	*file;

	i = -1;
	dir = NULL;
	while (path_dir[++i])
	{
		if (!(dir = opendir(path_dir[i])))
			continue ;
		while ((file = readdir(dir)))
		{
			if (!(ft_strcmp(file->d_name, cmd)))
			{
				closedir(dir);
				return (i);
			}
		}
		closedir(dir);
	}
	return (-1);
}

int		check_utility(char **cmd)
{
	int		num;
	char	**path_dir;

	if (cmd[0][0] == '/')
	{
		if (get_built(cmd, NULL, -1))
			return (0);
	}
	if (!(path_dir = parse_path_dir(cmd)))
	{
		free_array(path_dir);
		return (1);
	}
	if ((num = search_cmd(path_dir, cmd[0])) == -1)
	{
		free_array(path_dir);
		return (1);
	}
	if (get_built(cmd, path_dir, num))
		return (0);
	return (1);
}

int		check_builtin(char **cmd)
{
	if (!(ft_strcmp(cmd[0], "echo")))
		echo_builtin(cmd + 1);
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
		return (1);
	return (0);
}

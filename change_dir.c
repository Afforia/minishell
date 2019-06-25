/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:52:13 by thaley            #+#    #+#             */
/*   Updated: 2019/06/25 20:05:46 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		*cd_home_path(void)
{
	int		pos;
	char	*path;
	int		len;

	len = ft_strlen("HOME=");
	pos = env_start("HOME=");
	path = ft_strsub(env[pos], len, ft_strlen(env[pos]) - len);
	new_pwd(path);
	return (path);
}

char		*cd_prev_dir(void)
{
	int		pos;
	char	*path;
	int		end;
	int		start;

	pos = env_start("PWD=");
	start = ft_strlen("PWD=");
	end = ft_strlen(env[pos]);
	while (env[pos][end - 1] && env[pos][end - 1] != '/')
		end--;
	if (end - 1 == start)
		path = ft_strsub(env[pos], start, end - start);
	else
		path = ft_strsub(env[pos], start, end - start - 1);
	new_pwd(path);
	return (path);
}

void		change_dir(char **cmd)
{
	char	*path;

	path = NULL;
	if (cmd[1] && cmd[2])
	{
		ft_putstr("cd: string not in pwd: ");
		ft_putstr(cmd[1]);
	}
	if (!cmd[1] || !ft_strcmp(cmd[1], ".") || !ft_strcmp(cmd[1], "~"))
		path = cd_home_path();
	else if (cmd[1] && cmd[1][0] == '.' && cmd[1][1] == '.') //TODO: check atributes? а потом запускать переход для определенной задачи
		path = cd_prev_dir();
	// else if (cmd[1] && cmd[1][0] == '/')
	// 	path = cd_root();
	// else
	// 	path = cd_forward();
	chdir(path);
	if (path)
		free(path);
}

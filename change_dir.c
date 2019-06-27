/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:52:13 by thaley            #+#    #+#             */
/*   Updated: 2019/06/27 15:51:44 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		*cd_home_path(void)
{
	int		pos;
	int		old_pwd;
	char	*path;
	int		len;

	len = ft_strlen("HOME=");
	pos = env_start("HOME=");
	path = ft_strsub(env[pos], len, ft_strlen(env[pos]) - len);
	return (path);
}

char		*cd_oldpwd(void)
{
	char	*path;
	int		pos;

	pos = env_start("OLDPWD=");
	path = ft_strsub(env[pos], 7, ft_strlen(env[pos]) - 7);
	return (path);
}

void		change_dir(char **cmd)
{
	char	*path;

	path = NULL;
	if (cmd[0] && cmd[1])
	{
		ft_putstr("cd: string not in pwd: ");
		ft_putstr(cmd[0]);
		return ;
	}
	if (!cmd[0] || !ft_strcmp(cmd[0], ".") || !ft_strcmp(cmd[0], "~"))
		path = cd_home_path();
	else if (cmd[0] && !ft_strcmp(cmd[0], "-"))
		path = cd_oldpwd();
	else
		path = ft_strdup(cmd[0]);
	if ((chdir(path)) < 0)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(cmd[0]);
		free(path);
		return ;
	}
	change_pwd(path);
}

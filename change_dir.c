/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 20:17:15 by thaley            #+#    #+#             */
/*   Updated: 2019/06/28 16:13:29 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		*fullpath_from_short(int num)
{
	char	*new;
	int		pos;

	if (num == 1)
	{
		pos = env_start("HOME=");
		new = ft_strsub(env[pos], 5, ft_strlen(env[pos]) - 5);
	}
	else if (num == 2)
	{
		pos = env_start("OLDPWD=");
		new = ft_strsub(env[pos], 7, ft_strlen(env[pos]) - 7);
	}
	return (new);
}

void		rewrite_pwd(void)
{
	char	buf[4097];
	char	*cwd;

	cwd = getcwd(buf, 4096);
	change_pwd(cwd);
}

void		change_dir(char **cmd)
{
	char	*input;
	int		i;

	i = -1;
	if (cmd[0] && cmd[1])
	{
		erroring("cd", cmd[0],  2);
		return ;
	}
	if (!cmd[0] || !ft_strcmp(cmd[0], ".") || !ft_strcmp(cmd[0], "~"))
		input = fullpath_from_short(1);
	else if (!ft_strcmp(cmd[0], "-"))
		input = fullpath_from_short(2);
	else if (cmd[0])
		input = ft_strdup(cmd[0]);
	if ((chdir(input)) < 0)
	{
		erroring("cd", input, 1);
		return ;
	}
	else
		change_pwd();
}

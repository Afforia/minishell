/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 20:17:15 by thaley            #+#    #+#             */
/*   Updated: 2019/07/03 18:10:23 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		*fullpath_from_short(int num)
{
	char	*new;
	int		pos;

	new = NULL;
	if (num == 1)
	{
		pos = env_start("HOME=");
		new = ft_strsub(g_env[pos], 5, ft_strlen(g_env[pos]) - 5);
	}
	else if (num == 2)
	{
		pos = env_start("OLDPWD=");
		new = ft_strsub(g_env[pos], 7, ft_strlen(g_env[pos]) - 7);
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

char		*from_homepath(char *cmd)
{
	char	*new;
	char	*tmp;
	char	*home;
	int		pos;

	tmp = ft_strsub(cmd, 1, ft_strlen(cmd) - 1);
	pos = env_start("HOME=");
	home = parse_path(g_env[pos], 5);
	new = ft_strjoin(home, tmp);
	free(tmp);
	free(home);
	return (new);
}

int			check_input(char *input)
{
	if (access(input, F_OK))
		erroring("cd", input, 1);
	else if (access(input, X_OK))
		erroring("cd", input, 4);
	else
		return (0);
	free(input);
	return (1);
}

void		change_dir(char **cmd)
{
	char	*input;
	int		i;

	i = -1;
	input = NULL;
	if (cmd[0] && cmd[1])
	{
		erroring("cd", cmd[0], 2);
		return ;
	}
	if (!cmd[0] || !ft_strcmp(cmd[0], ".") || !ft_strcmp(cmd[0], "~"))
		input = fullpath_from_short(1);
	else if (cmd[0][0] == '~')
		input = from_homepath(cmd[0]);
	else if (!ft_strcmp(cmd[0], "-"))
		input = fullpath_from_short(2);
	else if (cmd[0])
		input = ft_strdup(cmd[0]);
	if (check_input(input))
		return ;
	if ((chdir(input)) < 0)
		;
	else
		change_pwd();
	free(input);
}

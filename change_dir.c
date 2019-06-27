/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 20:17:15 by thaley            #+#    #+#             */
/*   Updated: 2019/06/27 22:16:17 by thaley           ###   ########.fr       */
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

char		**parse_args(char *cmd, int len)
{
	char	**new;
	int		start;
	int		end;
	int		i;

	start = 0;
	end = -1;
	i = 0;
	new = (char **)malloc(sizeof(char *) * len);
	while (cmd[++end])
	{
		if (end == 0 && !ft_strcmp(cmd, "-"))
			new[i++] = fullpath_from_short(2);
		else if (cmd[end] == '/' || cmd[end + 1] == '\0')
		{
			new[i] = ft_strsub(cmd, start, end + 1 - start);
			start = end + 1;
			i++;
		}
	}
	new[i] = NULL;
	return (new);
}

char		**take_args(char *cmd)
{
	char	**new;
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (cmd[++i])
	{
		if (cmd[i] == '/' || cmd[i + 1] == '\0')
			len++;
	}
	new = parse_args(cmd, len);
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
	char	**input;
	int		i;

	i = -1;
	if (cmd[0] && cmd[1])
	{
		erroring("cd", cmd[0],  2);
		return ;
	}
	if (!cmd[0] || !ft_strcmp(cmd[0], ".") || !ft_strcmp(cmd[0], "~"))
	{
		input = (char **)malloc(sizeof(char *) + 1);
		input[0] = fullpath_from_short(1);
		input[1] = NULL;
	}
	else if (cmd[0])
		input = take_args(cmd[0]);
	while (input[++i])
	{
		if ((chdir(input[i])) < 0)
		{
			erroring("cd", input[i], 1);
			if (input)
				free_array(&input);
			return ;
		}
		else
			change_pwd();
	}
}

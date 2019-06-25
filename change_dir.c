/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:52:13 by thaley            #+#    #+#             */
/*   Updated: 2019/06/25 17:27:57 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		*parse_path(char *env, int	start)
{
	char	*new;

	if (!env)
		return (NULL);
	new = ft_strsub(env, start, (ft_strlen(env) - start));
	return (new);
}

int			find_env(char *search_string)
{
	int		pos;

	pos = -1;
	while (env[++pos])
	{
		if (env_start(env[pos], search_string))
			return (pos);
	}
	return (0);
}

char		*cd_home_path(void)
{
	int		pos;
	char	*path;
	int		len;

	len = ft_strlen("HOME=");
	pos = find_env("HOME=");
	path = ft_strsub(env[pos], len, ft_strlen(env[pos]) - len);
	pos = find_env("PWD=");
	free(env[pos]);
	env[pos] = ft_strjoin("PWD=", path);
	return (path);
}

char		*cd_prev_dir(void)
{
	int		pos;
	char	*path;
	int		end;
	int		start;

	pos = find_env("PWD=");
	start = ft_strlen("PWD=");
	end = ft_strlen(env[pos]);
	while (env[pos][end - 1] && env[pos][end - 1] != '/')
		end--;
	if (end - 1 == start)
		path = ft_strsub(env[pos], start, end - start);
	else
		path = ft_strsub(env[pos], start, end - start - 1);
	free(env[pos]);
	env[pos] = ft_strjoin("PWD=", path);
	write(1, "\n", 1);
	ft_putstr(env[pos]);
	write(1, "\n", 1);
	return (path);
}

void		change_dir(char **cmd)
{
	char	*path;

	if (cmd[1] && cmd[2])
	{
		ft_putstr("cd: string not in pwd: ");
		ft_putstr(cmd[1]);
	}
	if (!cmd[1] || !ft_strcmp(cmd[1], ".") || !ft_strcmp(cmd[1], "~"))
		path = cd_home_path();
	else if (cmd[1] && !ft_strcmp(cmd[1], ".."))
		path = cd_prev_dir();
	else if (cmd[1] && cmd[1][0] == '/')
		path = cd_root();
	else
		path = cd_forward();
	ft_putstr(path);
	write(1, "\n", 1);
	chdir(path);
	free(path);
	path = NULL;
}

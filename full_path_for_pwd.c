/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_path_for_pwd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:32:24 by thaley            #+#    #+#             */
/*   Updated: 2019/06/27 22:20:19 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			count_step_back(char *str)
{
	int		count;
	int		i;

	i = 1;
	count = 1;
	while (str[++i])
	{
		if (str[i] == '.' && str[i + 1] == '.')
			count++;
		if (str[i] != '.' && str[i] != '/')
			break ;
	}
	return (count);
}

char		*remove_slash(char *tmp)
{
	char	temp[1024];
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (tmp[++i])
	{
		while (tmp[i] == '/' && tmp[i + 1] == '/')
			i++;
		temp[j] = tmp[i];
		j++;
	}
	temp[j] = '\0';
	new = ft_strdup(temp);
	return (new);
}

char		*right_dir(char *dir)
{
	int		i;
	int		j;
	char	tmp[1025];

	i = -1;
	j = 0;
	while (dir[++i])
	{
		if (dir[i] == '.' && dir[i + 1] == '.')
			i += 2;
		tmp[j] = dir[i];
		j++;
	}
	tmp[j] = '\0';
	if (dir)
		free(dir);
	dir = remove_slash(tmp);
	return (dir);
}

char		*take_corr_path(char *dir, int count_step)
{
	char	*tmp;
	char	*path;
	int		pos;
	int		end;
	int		len;

	pos = env_start("PWD=");
	end = ft_strlen(env[pos]);
	while (--end > 3 && env[pos][end])
	{
		if (env[pos][end - 1] == '/')
		{
			count_step--;
			if (count_step == 0)
				break ;
		}
	}
	tmp = ft_strsub(env[pos], 4, end - 4);
	dir = right_dir(dir);
	path = ft_strjoin(tmp, dir);
	if (tmp)
		free(tmp);
	return (path);
}

char		*fullpath_prevdir(char *str)
{
	int		count_step;
	int		i;
	char	*tmp;
	char	*path;

	tmp = NULL;
	path = NULL;
	count_step = count_step_back(str);
	i = count_step * 3;
	tmp = ft_strsub(str, i, ft_strlen(str) - i);
	path = take_corr_path(tmp, count_step);
	if (str)
		free(str);
	return (path);
}

char		*take_full_path(char *str)
{
	int		pos;
	int		i;
	char	*tmp;
	char	*pwd_tmp;

	i = -1;
	if (str[0] == '.' && str[1] == '/')
	{
		pos = env_start("PWD=");
		while (str[++i])
		{
			if (str[i] != '.' && str[i + 1] != '/')
				break;
		}
		if (str[i] == '\0')
			tmp = ft_strsub(env[pos], 4, ft_strlen(env[pos]) - 4);
		else
		{
			tmp = ft_strsub(str, i, ft_strlen(str) - i);
			pwd_tmp = ft_strsub(env[pos], 4, ft_strlen(env[pos]) - 4);
			if (str)
				free(str);
			str = ft_strjoin(pwd_tmp, tmp);
			if (pwd_tmp)
				free(pwd_tmp);
			if (tmp)
				free(tmp);
		}
	}
	else
		str = fullpath_prevdir(str);
	return (str);
}

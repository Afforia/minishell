/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_path_for_pwd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:32:24 by thaley            #+#    #+#             */
/*   Updated: 2019/06/27 16:52:04 by thaley           ###   ########.fr       */
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
	path = ft_strjoin(tmp, dir);
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
			free(str);
			str = ft_strjoin(pwd_tmp, tmp);
			free(pwd_tmp);
			free(tmp);
		}
	}
	else
		str = fullpath_prevdir(str);
	return (str);
}

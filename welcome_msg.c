/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome_msg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 15:15:46 by thaley            #+#    #+#             */
/*   Updated: 2019/06/24 22:11:39 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		env_start(char *env, char *search_string)
{
	int		i;
	int		len;

	len = ft_strlen(search_string);
	i = 0;
	while (env[i] && search_string[i] && len)
	{
		if (env[i] != search_string[i])
			return (0);
		i++;
		len--;
	}
	return (1);
}

int		cmp_path(char *env, char *cwd)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (env[i] && env[i] != '=')
		i++;
	i++;
	while (env[i + j] && cwd[j])
	{
		if (env[i + j] != cwd[j])
			return (0);
		j++;
	}
	if (env[i + j] == '\0' && cwd[j] == '\0')
		return (1);
	else
		return (0);
}

int		check_home_path(char *cwd, char **env)
{
	int	i;
	int	check;

	i = -1;
	check = 0;
	while (env[++i])
	{
		if (env_start(env[i], "HOME="))
		{
			check = 1;
			break ;
		}
	}
	if (check)
	{
		if (cmp_path(env[i], cwd))
			return (1);
	}
	return (0);
}

char	*parse_path(char *cwd, char **env)
{
	char	*new;
	int		start;
	int		len;

	new = NULL;
	len = 0;
	if (check_home_path(cwd, env))
		new = ft_strdup("~");
	else
	{
		start = ft_strlen(cwd);
		while (cwd[--start])
		{
			len++;
			if (cwd[start] == '/')
				break ;
		}
		new = ft_strsub(cwd, start + 1, len);
	}
	return (new);
}

void	print_welcome_msg(char **env)
{
	char	*cwd;
	char	*path;
	char	buf[4097];

	cwd = getcwd(buf, 4096);
	path = parse_path(cwd, env);
	ft_putstr("\33[01;35m");
	ft_putstr(path);
	write(1, " ", 1);
	ft_putstr("\33[01;35m>>\33[0m ");
	free(path);
}

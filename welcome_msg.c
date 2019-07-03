/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome_msg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 15:15:46 by thaley            #+#    #+#             */
/*   Updated: 2019/07/02 22:05:23 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		cmp_path(char *g_env, char *cwd)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (g_env[i] && g_env[i] != '=')
		i++;
	i++;
	while (g_env[i + j] && cwd[j])
	{
		if (g_env[i + j] != cwd[j])
			return (0);
		j++;
	}
	if (g_env[i + j] == '\0' && cwd[j] == '\0')
		return (1);
	else
		return (0);
}

int		check_home_path(char *cwd)
{
	int	i;

	i = 0;
	if ((i = env_start("HOME=")) > 0)
	{
		if (cmp_path(g_env[i], cwd))
			return (1);
	}
	return (0);
}

char	*parse_print_path(char *cwd)
{
	char	*new;
	int		start;
	int		len;

	new = NULL;
	len = 0;
	if (check_home_path(cwd))
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
		new = ft_strsub(cwd, start, len);
	}
	return (new);
}

void	print_welcome_msg(void)
{
	char	*cwd;
	char	*path;
	char	buf[4097];

	cwd = getcwd(buf, 4096);
	path = parse_print_path(cwd);
	ft_putstr("\33[01;36m⇒ ");
	ft_putstr("\33[01;33m");
	ft_putstr(path);
	ft_putstr("\33[0m ");
	free(path);
}

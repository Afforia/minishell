/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:45:05 by thaley            #+#    #+#             */
/*   Updated: 2019/07/03 18:18:31 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	**write_path_dir(char **path_dir, int start, int end, int pos)
{
	int		i;

	i = 0;
	while (g_env[pos][++end])
	{
		if (g_env[pos][end] == ':' || g_env[pos][end + 1] == '\0')
		{
			g_env[pos][end + 1] == '\0' ? end++ : 0;
			path_dir[i] = ft_strsub(g_env[pos], start, end - start);
			i++;
			if (!g_env[pos][end])
				break ;
			start = end + 1;
		}
	}
	path_dir[i] = NULL;
	return (path_dir);
}

char	**parse_path_dir(void)
{
	char	**path_dir;
	int		pos;
	int		end;
	int		start;

	end = 4;
	start = 5;
	if ((pos = env_start("PATH=")) == -1)
		return (NULL);
	path_dir = (char **)malloc(sizeof(char *) * count_dir(pos) + 1);
	path_dir = write_path_dir(path_dir, start, end, pos);
	return (path_dir);
}

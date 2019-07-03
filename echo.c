/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 07:48:01 by thaley            #+#    #+#             */
/*   Updated: 2019/07/03 18:11:15 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	find_start_end(char **cmd, int *start, int *end, int i)
{
	int		j;

	while (cmd[++i])
	{
		j = -1;
		while (cmd[i][++j])
		{
			if (j == 0 && cmd[i][j] == '"')
				(*start) = 1;
			else if (j == 0 && cmd[i][j] == '\\')
				(*start) = 2;
			if (cmd[i][j + 1] == '\0' && cmd[i][j] == '"')
				(*end) = 1;
			else if (cmd[i][j + 1] == '\0' && cmd[i][j] == '\\')
				(*end) = 2;
			else if (cmd[i][j + 1] == '\0')
				(*end) = 0;
		}
	}
}

void	echo_builtin(char **cmd)
{
	int		flag;
	int		start;
	int		end;
	int		i;

	flag = 0;
	if (!(ft_strcmp(cmd[0], "-n")))
		flag = 1;
	i = -1 + flag;
	start = 0;
	end = 0;
	find_start_end(cmd, &start, &end, i);
	print_echo(cmd + i + 1, start, end, flag);
}

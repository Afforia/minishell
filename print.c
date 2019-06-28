/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:10:30 by thaley            #+#    #+#             */
/*   Updated: 2019/06/28 21:36:06 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		echo_count(char **cmd, int flag)
{
	int		i;
	int		len;

	i = -1 + flag;
	while (cmd[++i])
		len++;
	return (len);
}

void	find_start_end(char **cmd, int start, int end, int i)
{
	int		j;

	while (cmd[++i])
	{
		j = -1;
		while (cmd[i][++j])
		{
			if (j == 0 && cmd[i][j] == '"')
				start = 1;
			else if (j == 0 && cmd[i][j] == '\\')
				start = 2;
			if (cmd[i][j + 1] == '\0' && cmd[i][j])
		}
	}
}

void	print_echo(char **cmd)
{
	int		flag;
	int		start;
	int		end;
	int		i;
	char	**tmp;

	flag = 0;
	if (!(ft_strcmp(cmd[0], "-n")))
		flag = 1;
	i = -1 + flag;
	start = 0;
	end = 0;
	tmp = (char **)malloc(sizeof(char *) * (echo_count(cmd, flag) + 1));
	find_start_end(cmd, &start, &end, i);
}

void		print_env(void)
{
	int		i;

	i = -1;
	while (env[++i])
	{
		ft_putstr(env[i]);
		write(1, "\n", 1);
	}
}

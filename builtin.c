/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:20:43 by thaley            #+#    #+#             */
/*   Updated: 2019/06/24 20:17:46 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	print_echo(char **cmds)
{
	int		start;
	int		finish;
	int		i;

	i = 0;
	while (cmds[++i])
	{
		start = 0;
		finish = ft_strlen(cmds[i]);
		if (cmds[i][0] == '"')
			start++;
		if (start)
			finish--;
		while (start < finish)
		{
			write(1, &cmds[i][start], 1);
			start++;
		}
		if (cmds[i + 1])
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}

int		check_builtin(char **cmds)
{
	if (!(ft_strcmp(cmds[0], "echo")))
		print_echo(cmds);
	if (!(ft_strcmp(cmds[0], "exit")))
		exit_shell(cmds, 0);
	return (0);
}

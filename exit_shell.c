/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 14:55:39 by thaley            #+#    #+#             */
/*   Updated: 2019/07/02 22:02:09 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	free_array(char **arr)
{
	int		i;

	i = -1;
	if (!arr)
		return ;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	arr = NULL;
}

void	exit_shell(char **arr, int error)
{
	if (g_env)
	{
		free_array(g_env);
		g_env = NULL;
	}
	if (arr)
	{
		free_array(arr);
		arr = NULL;
	}
	if (error == -1)
	{
		ft_putstr("Not enough space/cannot allocate memory.\n");
		exit(0);
	}
	if (error == 0)
		exit(EXIT_SUCCESS);
}

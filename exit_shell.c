/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 14:55:39 by thaley            #+#    #+#             */
/*   Updated: 2019/06/25 19:19:40 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	free_array(char ***arr)
{
	int		i;

	i = 0;
	while ((*arr)[i])
	{
		free((*arr)[i]);
		i++;
	}
	free((*arr));
}

void	exit_shell(char **arr, int error)
{
	free_array(&env);
	env = NULL;
	if (arr)
		free_array(&arr);
	if (error == -1)
	{
		ft_putstr("Not enough space/cannot allocate memory.\n");
		exit(0);
	}
	if (error == 0)
		exit(EXIT_SUCCESS);
}

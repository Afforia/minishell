/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:08:53 by thaley            #+#    #+#             */
/*   Updated: 2019/07/02 21:25:32 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	**split_all(char *input)
{
	char	**new;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	if ((len = count_words(input)) == 0)
		return (NULL);
	if (!(new = (char **)malloc(sizeof(char *) * len + 1)))
		exit_shell(NULL, -1);
	while (input[i])
	{
		SPACES(input[i]) ? i++ : 0;
		if (input[i] && !SPACES(input[i]))
		{
			if (!(new[j] = ft_strsub(input, i, word_len(input, i))))
				exit_shell(new, -1);
			while (input[i] && !SPACES(input[i]))
				i++;
			j++;
		}
	}
	new[j] = NULL;
	return (new);
}

char	**write_cmds(char *input, int count, char **new)
{
	int		begin;
	int		end;
	int		i;

	i = 0;
	begin = 0;
	end = 0;
	while (input[end] && count)
	{
		if (input[end + 1] == ';' || input[end + 1] == '\0')
		{
			!(new[i] = ft_strsub(input, begin, end + 1 - begin))
			? exit_shell(new, -1) : 0;
			count--;
			begin = end + 2;
			i++;
		}
		end++;
	}
	new[i] = NULL;
	return (new);
}

char	**split_cmds(char *input)
{
	char	**new;
	int		count;

	count = count_cmds(input);
	!(new = (char **)malloc(sizeof(char *) * count + 1))
	? exit_shell(NULL, -1) : 0;
	new = write_cmds(input, count, new);
	free(input);
	return (new);
}

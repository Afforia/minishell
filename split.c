/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:08:53 by thaley            #+#    #+#             */
/*   Updated: 2019/06/25 19:37:06 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		count_words(char *input)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] && SPACES(input[i]))
			i++;
		if (input[i] && !SPACES(input[i]))
			len++;
		while (input[i] && !SPACES(input[i]))
			i++;
	}
	return (len);
}

int		word_len(char *input, int i)
{
	int		len;

	len = 0;
	while (input[i + len])
	{
		if (SPACES(input[i + len]))
			return (len);
		len++;
	}
	return (len);
}

char	**split_all(char *input)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = (char **)malloc(sizeof(char *) * count_words(input) + 1);
	while (input[i])
	{
		if (SPACES(input[i]))
			i++;
		if (input[i] && !SPACES(input[i]))
		{
			new[j] = ft_strsub(input, i, word_len(input, i));
			while (input[i] && !SPACES(input[i]))
				i++;
			j++;
		}
	}
	new[j] = NULL;
	return (new);
}

int		count_cmds(char *str)
{
	int		i;
	int		count;

	count = 1;
	i = -1;
	while (str[++i])
	{
		if (str[i] == ';')
			count++;
	}
	return (count);
}

char	**split_cmds(char *input)
{
	char	**new;
	int		count;
	int		i;
	int		begin;
	int		end;

	i = 0;
	begin = 0;
	count = count_cmds(input);
	new = (char **)malloc(sizeof(char *) * count + 1);
	while (input[end] && count)
	{
		if (input[end + 1] == ';' || input[end + 1] == '\0')
		{
			new[i] = ft_strsub(input, begin, end + 1);
			count--;
			begin = end + 2;
			i++;
		}
		end++;
	}
	new[i] = NULL;
	return (new);
}

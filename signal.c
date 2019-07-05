/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:31:05 by thaley            #+#    #+#             */
/*   Updated: 2019/07/05 17:14:13 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void			signal_handler_aux(int sign)
{
	if (sign == SIGINT)
	{
		write(1, "\n", 1);
		signal(SIGINT, signal_handler_aux);
	}
}

void			signal_handler(int sign)
{
	if (sign == SIGINT)
	{
		ft_putstr("\b\b  \n");
		print_welcome_msg();
		signal(SIGINT, signal_handler);
	}
}

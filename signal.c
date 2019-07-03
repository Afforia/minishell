/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:31:05 by thaley            #+#    #+#             */
/*   Updated: 2019/07/02 20:26:16 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void			signal_handler(int sign)
{
	if (sign == SIGINT)
	{
		write(1, "\n", 1);
		print_welcome_msg();
		signal(SIGINT, signal_handler);
	}
}

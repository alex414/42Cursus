/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 00:35:28 by adiaz-do          #+#    #+#             */
/*   Updated: 2021/06/27 20:09:02 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft.h"
#include "minitalk.h"

void	send_char(int pid, unsigned char byte)
{
	uint8_t		counter;

	counter = 1 << 6;
	while (counter)
	{
		if (byte & counter)
		{
			if (kill(pid, SIGUSR1) == -1)
				error("Incorrect PID\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error("Incorrect PID\n");
		}
		counter >>= 1;
		usleep(900);
	}
}

void	main_handler(char *str_pid, char *msg)
{
	int			pid;

	pid = ft_atoi(str_pid);
	while (*msg)
	{
		send_char(pid, *msg);
		++msg;
	}
	send_char(pid, *msg);
}

void	success(int sig)
{
	(void)sig;
	write(1, "Enviado!\n", 10);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "PID y Cadena :D!\n", 18);
		return (0);
	}
	signal(SIGUSR1, success);
	main_handler(argv[1], argv[2]);
	return (0);
}

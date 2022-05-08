/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 00:35:38 by adiaz-do          #+#    #+#             */
/*   Updated: 2021/06/27 20:36:13 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "minitalk.h"
#include "libft.h"

void	activebit(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	(void)info;
	if (!g_bitwise.top_bit)
	{
		g_bitwise.top_bit = 1 << 6;
		++(g_bitwise.top_byte);
	}
	g_bitwise.msg[g_bitwise.top_byte] += g_bitwise.top_bit;
	g_bitwise.top_bit >>= 1;
	if (g_bitwise.top_byte == BUFFSIZE - 2 && !g_bitwise.top_bit)
		g_bitwise.buff_overflow = TRUE;
}

void	nullbit(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	if (!g_bitwise.top_bit)
	{
		g_bitwise.top_bit = 1 << 6;
		++(g_bitwise.top_byte);
	}
	g_bitwise.top_bit >>= 1;
	if (g_bitwise.top_byte == BUFFSIZE - 2 && !g_bitwise.top_bit)
		g_bitwise.buff_overflow = TRUE;
	else if (!g_bitwise.msg[g_bitwise.top_byte]
		&& !g_bitwise.top_bit)
	{
		g_bitwise.all_receive = TRUE;
		kill(info->si_pid, SIGUSR1);
	}
}

_Bool	main_handler(void)
{
	while (1)
	{
		pause();
		if (g_bitwise.all_receive || g_bitwise.buff_overflow)
		{
			write(1, g_bitwise.msg, ft_strlen(g_bitwise.msg));
			ft_bzero(g_bitwise.msg, BUFFSIZE);
			g_bitwise.top_byte = 0;
			g_bitwise.top_bit = 1 << 6;
			if (g_bitwise.all_receive)
				write(1, "\n", 1);
			g_bitwise.all_receive = FALSE;
			g_bitwise.buff_overflow = FALSE;
		}
	}
	return (TRUE);
}

int	main(void)
{
	struct sigaction	active_act;
	struct sigaction	null_act;

	active_act.sa_sigaction = activebit;
	null_act.sa_sigaction = nullbit;
	active_act.sa_flags = SA_SIGINFO;
	null_act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &active_act, NULL) != 0)
		error("signal error\n");
	if (sigaction(SIGUSR2, &null_act, NULL) != 0)
		error("signal error\n");
	print_pid();
	ft_bzero(g_bitwise.msg, BUFFSIZE);
	main_handler();
}

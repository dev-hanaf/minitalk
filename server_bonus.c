/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 00:40:36 by ahanaf            #+#    #+#             */
/*   Updated: 2024/04/18 04:45:55 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int num)
{
	char	c;

	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	if (num >= 0 && num <= 9)
	{
		c = num + 48;
		write(1, &c, 1);
	}
	if (num > 9)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
}

t_data	g_data = {.counter = 0, .res = 0};

void	handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
	{
		g_data.res <<= 1;
		g_data.res |= 1;
	}
	else if (sig == SIGUSR2)
	{
		g_data.res <<= 1;
	}
	g_data.counter++;
	if (g_data.counter == 8)
	{
		write(1, &g_data.res, 1);
		if (g_data.res == '\0')
		{
			kill(info->si_pid, SIGUSR1);
		}
		g_data.counter = 0;
		g_data.res = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	write(1, "PID :", 5);
	ft_putnbr(pid);
	write(1, "\n", 1);
	sa.sa_sigaction = &handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (TRUE)
	{
		pause();
	}
}

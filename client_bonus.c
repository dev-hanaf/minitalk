/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 00:08:41 by ahanaf            #+#    #+#             */
/*   Updated: 2024/04/20 22:53:15 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_spid;

int	ft_atoi(char *str)
{
	long	result;
	int		sign;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		result = result * 10 + (*str - 48);
		if (result > INT_MAX)
		{
			write(2, RED"ERORR\nWrong Pid\n"NC, 23);
			exit(1);
		}
		str++;
	}
	return (result * sign);
}

void	send_bit(int pid, unsigned char c)
{
	int				i;
	unsigned char	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(350);
		i--;
	}
}

void	handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1 && info->si_pid == g_spid)
	{
		write(1, GREEN"message recieved succufuly!"NC, 27 + 7);
	}
	return ;
}

int	main(int ac, char *av[])
{
	int					pid;
	struct sigaction	sa;

	if (ac != 3)
	{
		write(1, "Takes tree arguments\n", 21);
		return (0);
	}
	pid = ft_atoi(av[1]);
	if (pid == 0 || pid == -1)
	{
		write(1, "Invalid PID\n", 12);
		return (0);
	}
	g_spid = pid;
	sa.sa_sigaction = &handler;
	sigaction(SIGUSR1, &sa, NULL);
	while (*av[2])
	{
		send_bit(pid, (unsigned char)*av[2]);
		av[2]++;
		usleep(500);
	}
	send_bit(pid, '\0');
}

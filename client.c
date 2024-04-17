/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 00:08:41 by ahanaf            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/04/17 16:11:42 by ahanaf           ###   ########.fr       */
=======
/*   Updated: 2024/04/15 17:54:37 by ahanaf           ###   ########.fr       */
>>>>>>> bbc2242189290442f877b9936379281b9e81ae0c
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

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
		str++;
	}
	return (result * sign);
}

void	send_bit(int pid, unsigned char c)
{
<<<<<<< HEAD
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
		usleep(1500);
		i--;
	}
}

int	main(int ac, char *av[])
=======
    int i;
    unsigned char bit;
    
    i = 7;
    while (i >= 0)
    {
        bit = (c >> i) & 1;
        if (bit)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(1500);
        i--;    
    }
}


#include <time.h>

int main(int ac, char *av[])
>>>>>>> bbc2242189290442f877b9936379281b9e81ae0c
{
	int	pid;

<<<<<<< HEAD
	if (ac != 3)
	{
		write(1, "Takes tree arguments\n", 21);
		return (0);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		write(1, "Invalid PID\n", 13);
		return (0);
	}
	while (*av[2])
	{
		send_bit(pid, (unsigned char)*av[2]);
		av[2]++;
	}
}
=======
    pid = ft_atoi(av[1]);
    if (pid <= 0)
    {
        write(1 ,"Invalid PID\n", 13);
        return (0);
    }
    while (*av[2])
    {
        send_bit(pid, (unsigned char)*av[2]);
        av[2]++;
    }
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    while (*av[2])
    {
        send_bit(pid, (unsigned char)*av[2]);
        av[2]++;
    }

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken to send 100 characters: %f seconds\n", cpu_time_used);
}
>>>>>>> bbc2242189290442f877b9936379281b9e81ae0c

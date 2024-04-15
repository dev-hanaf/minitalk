/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 00:08:41 by ahanaf            #+#    #+#             */
/*   Updated: 2024/04/14 20:00:36 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int ft_atoi(char *str)
{
    int result;
    int sign;

    sign = 1;
    result = 0;
    while((*str >= 9 && *str <= 13) || *str == 32)
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

void send_bit(int pid, unsigned char c)
{
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
        usleep(300);
        i--;    
    }
}


int main(int ac, char *av[])
{
    if (ac != 3)
    {
        write(1, "Takes tree arguments\n", 22);
        return (0);
    }
    
    int pid;

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
    // send_bit(pid, '\n');
    
}
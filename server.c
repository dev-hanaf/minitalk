/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 00:40:36 by ahanaf            #+#    #+#             */
/*   Updated: 2024/04/14 19:52:23 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#define TRUE 1
typedef struct s_data
{
    unsigned char res;
    int counter;
}   t_data;

void ft_putnbr(int num)
{
    char c;
    
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
t_data data = {.counter = 0, .res = 0 };

void handler(int sig)
{
    if (sig == SIGUSR1)
    {
        data.res <<= 1;
        data.res |= 1; 
    }
    else if (sig == SIGUSR2)
    {
        data.res <<= 1;
    }
    data.counter++;
    if (data.counter == 8)
    {
        write(1, &data.res, 1);
        data.counter = 0;
        data.res = 0;
    }
}

int main()
{

    int pid;

    pid = getpid();
    write(1,"PID :", 5);
    ft_putnbr(pid);
    write(1,"\n", 1);
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    while (TRUE)
    {
        pause();
    }

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:52:31 by ahanaf            #+#    #+#             */
/*   Updated: 2024/04/18 04:45:08 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#define Black "\033[0;30m"
#define Dark 	"\033[1;30m"
#define Red	"\033[0;31m"
#define LightRed		"\033[1;31m"
#define Green	"\033[0;32m"
#define LightGreen		"\033[1;32m"
#define Brown		"\033[0;33m"
#define Yellow		"\033[1;33m"
#define Blue		"\033[0;34m"
#define Light Blue		"\033[1;34m"
#define Purple		"\033[0;35m"
#define LightPurple		"\033[1;35m"
#define Cyan	"\033[0;36m"
#define LightCyan	"\033[1;36m"
#define LightGray	"\033[0;37m"
#define White		"\033[1;37m"
#define NC		"\033[0;0m"


# include <limits.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0

typedef struct s_data
{
	unsigned char	res;
	int				counter;
}					t_data;

#endif
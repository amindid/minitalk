/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:30:57 by aouchaad          #+#    #+#             */
/*   Updated: 2023/01/11 22:03:00 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_count = 0;

char	to_ascii(char *str)
{
	int	i;
	int	j;
	int	power;
	int	car;

	i = 7;
	car = 0;
	while (str && i >= 0)
	{
		power = 1;
		if (str[i] == '1')
		{
			j = 7 - i;
			while (j-- > 0)
				power *= 2;
			car += power;
		}
		i--;
	}
	return (car);
}

void	str_funct(char c, char *str)
{
	str[g_count] = c;
	g_count++;
	if (g_count == 8)
	{
		ft_printf ("%c", to_ascii(str));
		g_count = 0;
	}
}

void	sig_handler(int signum, siginfo_t *info, void *cont)
{
	static char	str[8];
	static int	pid;

	(void)cont;
	if (pid != info->si_pid)
	{
		g_count = 0;
		pid = info->si_pid;
	}
	if (SIGUSR1 == signum)
		str_funct ('1', str);
	else if (SIGUSR2 == signum)
		str_funct ('0', str);
}

int	main(void)
{
	pid_t				s_pid;
	struct sigaction	sa;

	sa.sa_sigaction = sig_handler;
	sa.sa_flags = 0;
	s_pid = getpid();
	ft_printf ("%d", s_pid);
	write (1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:30:13 by aouchaad          #+#    #+#             */
/*   Updated: 2023/01/17 18:11:03 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	g_str[32];

char	*to_binary(unsigned char car)
{
	int		i;

	i = 0;
	while (i < 32)
		g_str[i++] = '0';
	if (car == '\0')
		return (g_str);
	i = 31;
	while ((int)car / 2 >= 0 && i >= 0)
	{
		if ((int)car % 2 == 1)
			g_str[i--] = '1';
		else
			g_str[i--] = '0';
		car = (int)car / 2;
	}
	return (g_str);
}

void	sign_handler(int signum)
{
	(void)signum;
	ft_printf("message reseived successfully");
}

void	funct(int av1, int j, int k)
{
	int	error;

	while (j < 32 && g_str[j] == '0')
	{
		j++;
		if (j >= 8 && j % 8 == 0)
			k++;
	}
	j = (k * 8);
	if (j == 32)
		j = 24;
	while (j < 32)
	{
		if (g_str[j] == '1')
			error = kill (av1, SIGUSR1);
		else if (g_str[j] == '0')
			error = kill (av1, SIGUSR2);
		if (error == -1)
			exit(-1);
		usleep(200);
		j++;
	}
}

int	main(int ac, char *av[])
{
	int		i;
	int		av_len;
	int		av1;

	i = 0;
	if (ac == 3)
	{
		av_len = ft_strlen (av[2]);
		av1 = ft_atoi(av[1]);
		signal(SIGUSR1, &sign_handler);
		while (i <= av_len)
		{
			if (av1 <= 1)
				exit(-1);
			to_binary((unsigned char)av[2][i]);
			funct(av1, 0, 0);
			i++;
		}
	}
	return (0);
}

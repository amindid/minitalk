/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:26:16 by aouchaad          #+#    #+#             */
/*   Updated: 2023/01/17 18:08:25 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	g_str[8];

char	*to_binary(char car)
{
	int		i;

	i = 0;
	while (i < 8)
		g_str[i++] = '0';
	i = 7;
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

void	funct(char *av2, int av1, int av_len)
{
	int		i;
	int		j;
	int		error;

	i = 0;
	while (i <= av_len)
	{
		to_binary(av2[i]);
		j = 0;
		while (j < 8)
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
		i++;
	}
}

int	main(int ac, char *av[])
{
	int	av1;
	int	av_len;

	if (ac == 3)
	{
		av_len = ft_strlen(av[2]);
		av1 = ft_atoi(av[1]);
		if (av1 <= 1)
			exit(-1);
		funct(av[2], av1, av_len);
	}
	return (0);
}

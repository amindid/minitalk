/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 22:44:14 by aouchaad          #+#    #+#             */
/*   Updated: 2023/01/06 16:39:55 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_put_str(char *str)
{
	int	i;

	if (!str)
	{
		ft_put_str("(null)");
		return (6);
	}
	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

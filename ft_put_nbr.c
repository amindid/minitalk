/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 22:55:31 by aouchaad          #+#    #+#             */
/*   Updated: 2023/01/17 18:01:31 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_put_nbr(long n)
{
	char	number;
	int		count;

	count = 0;
	if (n < 0)
	{
		count += ft_put_char('-');
		n *= -1;
	}
	if (n >= 10)
	{
		count += ft_put_nbr (n / 10);
		count += ft_put_nbr (n % 10);
	}
	number = n + '0';
	if (n >= 0 && n <= 9)
		count += ft_put_char(number);
	return (count);
}

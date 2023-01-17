/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsignd_deciml.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:03:25 by aouchaad          #+#    #+#             */
/*   Updated: 2023/01/17 16:11:11 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_put_unsignd_deciml(unsigned int n)
{
	int	count;

	count = 0;
	count += ft_put_nbr(n);
	return (count);
}

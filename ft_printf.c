/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:09:51 by aouchaad          #+#    #+#             */
/*   Updated: 2023/01/06 16:40:37 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	typs_func(va_list ptr, char c)
{
	if (c == '%')
		return (ft_put_char('%'));
	if (c == 'c')
		return (ft_put_char(va_arg(ptr, int)));
	if (c == 's')
		return (ft_put_str(va_arg(ptr, char *)));
	if (c == 'd' || c == 'i')
		return (ft_put_nbr(va_arg(ptr, int)));
	if (c == 'p')
		return (ft_put_adress(
				va_arg(ptr, size_t), "0123456789abcdef"));
	if (c == 'u')
		return (ft_put_unsignd_deciml(va_arg(ptr, unsigned int)));
	if (c == 'x')
		return (ft_put_hexadcml(va_arg(ptr, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_put_hexadcml(va_arg(ptr, unsigned int), "0123456789ABCDEF"));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ptr;
	int		count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			write (1, &str[i], 1);
			count++;
		}
		else
		{
			i++;
			count += typs_func(ptr, str[i]);
		}
		i++;
	}
	return (count);
}
// int main ()
// {
//     //int *p;
//     int d = -1;
// 	int c = 1;
//    // printf("%d\n", addnum(4,2,'c',2,2));
//     // printf("%X\n",p);
//     // printf("%i\n",p);
// 	ft_printf("%x\n",d);
//     printf("%x\n",d);
// 	ft_printf("%x\n",c);
//     printf("%x",c);
// }
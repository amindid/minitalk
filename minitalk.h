/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:36:18 by aouchaad          #+#    #+#             */
/*   Updated: 2023/01/14 15:44:20 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

int	ft_printf(const char *str, ...);
int	ft_put_adress(size_t n, char *base);
int	ft_put_char(char ptr);
int	ft_put_nbr(long n);
int	ft_put_str(char *str);
int	ft_put_hexadcml(long unsigned int n, char *base);
int	ft_put_unsignd_deciml(unsigned int n);
int	ft_strlen(char *string);
int	ft_atoi(char *string);

#endif

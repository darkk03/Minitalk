/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizenbe <aaizenbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:34:55 by aaizenbe          #+#    #+#             */
/*   Updated: 2024/02/09 20:34:55 by aaizenbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	res = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			neg = -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return (res * neg);
}

size_t	ft_strlen(const char *string)
{
	size_t	x;

	x = 0;
	while (string[x] != '\0')
		x++;
	return (x);
}

void	ft_putstr(char *s)
{
	int	n;

	if (!s)
	{
		write(1, "(null)", 6);
		return ;
	}
	n = ft_strlen(s);
	write(1, s, n);
}

void	ft_putnbr(long long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

void	ft_putchar(char c)
{
    write(1, &c, 1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizenbe <aaizenbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:23:53 by aaizenbe          #+#    #+#             */
/*   Updated: 2024/02/09 14:23:53 by aaizenbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, char *string, int len)
{
	int	i;
	int	j;
	int	bit;

	i = 0;
	while (i < len)
	{
		j = 7;
		while (j >= 0)
		{
			bit = (string[i] >> j) & 1;
			if (bit == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			j--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*string;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		string = argv[2];
		send_signal(pid, string, ft_strlen(string));
	}
	else
		ft_putstr("Error \n");
	return (0);
}

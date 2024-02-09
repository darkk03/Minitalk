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

void send_signal(int pid, char *string, int len)
{
    int i;
    int j;
    int k;
    int bit;

    i = 0;
    while (i < len)
    {
        j = 0;
        while (j < 8)
        {
            bit = (string[i] >> j) & 1;
            k = 0;
            while (k < 100000)
            {
                if (bit == 1)
                    kill(pid, SIGUSR1);
                else if(bit == 0)
                    kill(pid, SIGUSR2);
                k++;
            }
            j++;
        }
        i++;
    }
}

int main_client(int argc, char **argv)
{

    int pid;
    char *string;

    if (argc == 2)
    {
        pid = ft_atoi(argv[1]);
        string = argv[2];
        send_signal(pid, string, ft_strlen(string));
    }
    else
        ft_putstr("Error \n");
    return (0);
}

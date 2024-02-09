/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizenbe <aaizenbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:23:50 by aaizenbe          #+#    #+#             */
/*   Updated: 2024/02/09 14:23:50 by aaizenbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handler(int sig) 
{

    unsigned char buffer;
    int bits_received;

    buffer = 0;
    bits_received = 0;

    if (sig == SIGUSR1)
    {
        buffer |= (1 << bits_received);
    }
    bits_received++;

    if (bits_received == 8)
    {
        printf("%c", buffer);
        buffer = 0;
        bits_received = 0;
    }
}

int main_server()
{
    int pid = getpid();
    ft_putnbr(pid);
    while (1)
    {
        signal(SIGUSR1, handler);
        signal(SIGUSR2, handler);
        sleep(200);
    }
    return (0);
}
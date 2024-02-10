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
    static unsigned char buffer = 0;
    static int bits_received = 0;

    if (sig == SIGUSR1)
    {
        buffer |= (1 << (7 - bits_received));
    }
    bits_received++;

    if (bits_received == 8)
    {
        ft_putchar(buffer);
        buffer = 0;
        bits_received = 0;
    }
}

int main(void)
{
    int pid = getpid();
    ft_putnbr(pid);
    write(1, "\n", 1);
    while (1)
    {
        signal(SIGUSR1, handler);
        signal(SIGUSR2, handler);
        sleep(200);
    }
    return (0);
}
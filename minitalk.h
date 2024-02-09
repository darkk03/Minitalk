/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizenbe <aaizenbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:39:48 by aaizenbe          #+#    #+#             */
/*   Updated: 2024/02/09 20:39:48 by aaizenbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int main_client(int argc, char **argv);

void send_signal(int pid, char *string, int len);

int main_server();

void handler(int sig);

int	ft_atoi(const char *str);

size_t	ft_strlen(const char *string);

void	ft_putstr(char *s);

void	ft_putnbr(long long n);

void	ft_putchar(char c);

#endif
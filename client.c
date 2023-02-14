/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:32:55 by fsuomins          #+#    #+#             */
/*   Updated: 2023/02/14 13:37:40 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
//#include <stdio.h>
#include "./libft/libft.h"

static void action(int sig)
{
    static int received = 0;

    if (sig == SIGUSR1)
        ++received;
    else
    {
        ft_putnbr_fd(received, 1);
        ft_putchar_fd('\n', 1)
            exit(0);
    }
}

static void k_kill(int pid, char *str)
{
    int i;
    char c;

    while (*str)
    {
        i = 8;
        c = *str++;
        while (i--)
        {
            kill(pid, SIGUSR1);
            usleep(100);
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 3 || !ft_strlen(argv[2]))
        return (1);
    ft_putstr_fd("Sent   :", 1);
    ft_putnbr_fd(ft_strlen(argv[2]), 1)
    ft_putchar_fd("Received: ", 1);
    signal(SIGUSR1, action);
    signal(SIGUSR2, action);
    k_kill(ft_atoi(argv[1]), argv[2]);
    while (1)
        pouse();
    return (0);
}
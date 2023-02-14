/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:02:52 by fsuomins          #+#    #+#             */
/*   Updated: 2023/02/14 13:33:31 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "./libft/libft.h"

static void action(int sig, siginfo_t *info, void *context)
{
    static int              i = 0;
    static pid_t            client_pid = 0;
    static unsigned char    c = 0;

    (void)context;
    if (!client_pid)
        client_pid = info->si_pid;
    c |= (sig == SIGUSR2);
    if (++i == 8)
    {
        i = 0;
        if(!c)
        {
            kill(client_pid, SIGUSR2);
            client_pid = 0;
            return ;
        }
        ft_putchar_fd(c, 1);
        kill(client_pid, SIGUSR1);
    }
    else
        c <<= 1;
}

void main(void)
{
    struct sigaction    s_sigaction;

    ft_putstr_fd("Sent PID: ", 1);
    ft_putnbr_fd(getpid(), 1);
    ft_putchar_fd('\n, 1');
    s_sigation.sa_sigaction = action;
    s_sigation.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &s_sigaction, 0);
    sigaction(SIGUAR2, &s_sigaction, 0);
    while(1)
        pause();
    return(0);    
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:21:25 by j.fox             #+#    #+#             */
/*   Updated: 2026/02/14 17:37:54 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

// get the pid of the executable as it runs.
// print the process number.
static void print_pid(void)
{
	pid_t	server;

	server = getpid();
	ft_printf("%d\n", server);
	return ;
}

// set how to act when recieving signals from client.
static void	handle(int signal)
{
	static char c = 0;
	static int bits = 0;

	if (signal == SIGUSR1)
	{
        c |= (0b10000000 >> bits);
	}
    else if (signal == SIGUSR2)
	{
        c &= ~(0b10000000 >> bits);
	}
	bits++;
	if (bits == 8)
	{
		ft_printf("%c", c);
		c = 0;
		bits = 0;
	}
	// if (signal == SIGUSR1)
	// 	ft_printf("Hello\n");
	// if (signal == SIGUSR2)
	// 	ft_printf("World\n");
}

// print the servers pid, define sigaction struct.
// pause the executable until it recieves a signal, then print the result. 
int main(void)
{
	print_pid();
	struct sigaction process;
	process.sa_handler = handle;
	sigemptyset(&process.sa_mask);
	sigaction(SIGUSR1, &process, NULL);
    sigaction(SIGUSR2, &process, NULL);
	while (1)
		pause();
	return (0);
}

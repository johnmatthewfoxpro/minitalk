/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:21:19 by j.fox             #+#    #+#             */
/*   Updated: 2026/02/21 14:48:04 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

int	g_recieve = 0;

// this handle is purely to control the speed of the outgoing message.
// it's now dependant on recieving a return signal from the server.
static void	handle(int signal)
{
	if (signal == SIGUSR1)
		g_recieve = 1;
	if (signal == SIGUSR2)
		write(1, "==========Message was recieved==========\n", 41);
	return ;
}

// in reference to type. 0 represents an error with the initial arguments.
// in reference to type. 1 represents and error with the PID.
static void	error_handle(int args, int type)
{
	if (args < 3 && type == 0)
	{
		ft_printf("Exit status 1. Not enough arguments.\n");
		exit(1);
	}
	else if (args > 3 && type == 0)
	{
		ft_printf("Exit status 1. Too many arguments.\n");
		exit(1);
	}
	else if (type == 1)
	{
		ft_printf("Exit status 1. First argument must be the server PID.\n");
		exit(1);
	}
	return ;
}

// Using i as an iterator we check each digit of pid.
// Insuring it includes only numbers.
static int	check_pid(char *pid)
{
	int		i;

	i = 0;
	while (pid[i])
	{
		if (!ft_isdigit(pid[i]))
			return (0);
		i++;
	}
	return (1);
}

// Loop through the message, converting each char to binary with bitshift.
// Send each bit of the char until the message is complete.
// The usleep of 400 is justified. This allows the client to send:
// 100 chars in around 1 second. And 30,000 chars in around 135 seconds.
static void	send_message(pid_t serv_pid, char *message)
{
	int	i;
	int	bits;
	int	len;

	i = 0;
	len = ft_strlen(message);
	while (i <= len)
	{
		bits = 0;
		while (bits < 8)
		{
			if ((message[i] & (0b10000000 >> bits)))
				kill(serv_pid, SIGUSR1);
			else
				kill (serv_pid, SIGUSR2);
			while (!g_recieve)
				pause();
			g_recieve = 0;
			usleep(400);
			bits++;
		}
		i++;
	}
	return ;
}

// Error handle the imput parameters then convert server_pid string with atoi.
// Save input string to variable and then send to server.
// Send line return once message completes.
int	main(int argc, char **argv)
{
	pid_t				serv_pid;
	char				*message;
	struct sigaction	process;

	if (argc < 3 || argc > 3)
		error_handle(argc, 0);
	if (!check_pid(argv[1]))
		error_handle(argc, 1);
	ft_bzero(&process, sizeof(process));
	process.sa_handler = handle;
	sigemptyset(&process.sa_mask);
	sigaction(SIGUSR1, &process, NULL);
	sigaction(SIGUSR2, &process, NULL);
	serv_pid = ft_atoi(argv[1]);
	message = argv[2];
	send_message(serv_pid, message);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:21:25 by j.fox             #+#    #+#             */
/*   Updated: 2026/02/21 15:45:44 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

int	g_globalbit = 0;

// set how to act when recieving signals from client.
// static int counter keeps tracks of 0's, so we can return a special signal
// to the client when we hit the \0 at the end of our message.
static void	handle(int signal, siginfo_t *info, void *waste)
{
	static int	counter = 0;

	(void)waste;
	if (signal == SIGUSR1)
	{
		g_globalbit = 1;
		counter = 0;
	}
	else
	{
		g_globalbit = 0;
		counter++;
	}
	kill(info->si_pid, SIGUSR1);
	if (counter >= 8)
	{
		kill(info->si_pid, SIGUSR2);
		counter = 0;
	}
	return ;
}

// A modified strjoin from get_next_line project.
// This strjoin works very well in minitalk for building the string.
// It also frees within the function, helping solve leaks.
static char	*mt_strjoin(char *s1, char const *s2)
{
	char	*s3;
	size_t	len1;
	size_t	lenx;

	if (!s2)
		return (NULL);
	len1 = ft_strlen(s1);
	lenx = (len1 + ft_strlen(s2));
	s3 = (char *)ft_calloc((lenx + 1), sizeof(char));
	if (!s3)
		return (NULL);
	if (s1)
	{
		ft_strlcpy(s3, s1, (len1 + 1));
		free(s1);
	}
	ft_strlcpy(&s3[len1], s2, ft_strlen(s2) + 1);
	return (s3);
}

// Build the char bit by bit with bit shift.
static char	build_char(char c)
{
	static int	bits = 0;

	if (bits >= 8)
	{
		bits = 0;
	}
	if (g_globalbit == 1)
	{
		c |= (0b10000000 >> bits);
	}
	else
	{
		c &= ~(0b10000000 >> bits);
	}
	bits++;
	return (c);
}

// Here we build the string with the help of static variables.
// Each time we recieve a signal we change a bit in the build_char function.
// Once we have 8 bits, that char gets added to the string in strjoin.
// When we hit null, we print the string!
// IMPORTANT: Under Normal operation, there are no leaks in this function.
// STR is freed on recieving NULL. However if we force exit, this is not done.
static void	build_string(void)
{
	static char	c = 0;
	static char	*str = 0;
	static int	bits = 0;

	c = build_char(c);
	bits++;
	if (bits >= 8)
	{
		str = mt_strjoin(str, &c);
		if (c == '\0')
		{
			ft_printf("%s\n", str);
			free(str);
			str = NULL;
		}
		bits = 0;
		c = 0;
	}
	return ;
}

// get the pid of the server executable as it runs.
// print the servers pid, define sigaction struct.
// pause the executable until it recieves a signal, then print the result.
int	main(void)
{
	struct sigaction	process;
	pid_t				server;

	server = getpid();
	ft_printf("Server PID: %d\nWaiting for client...\n", server);
	ft_bzero(&process, sizeof(process));
	process.sa_sigaction = &handle;
	process.sa_flags = SA_SIGINFO;
	sigemptyset(&process.sa_mask);
	sigaction(SIGUSR1, &process, NULL);
	sigaction(SIGUSR2, &process, NULL);
	while (1)
	{
		pause();
		build_string();
	}
	return (0);
}

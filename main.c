/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: j.fox <jfox.42angouleme@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:07:21 by j.fox             #+#    #+#             */
/*   Updated: 2026/02/11 19:52:33 by j.fox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// create 2 executables, client and server              =COMPLETE=

// use a makefile, without unncessary relinking         =COMPLETE=
// libft allowed                                        =COMPLETE=

// full error handling

// no leaks

// one global variable per program. 1 client, 1 server.

// permitted to use the following 
// ◦ write
// ◦ ft_printf
// ◦ signal 
// ◦ sigemptyset 
// ◦ sigaddset 
// ◦ sigaction 
// ◦ kill 
// ◦ getpid 
// ◦ malloc 
// ◦ free 
// ◦ pause 
// ◦ sleep 
// ◦ usleep 
// ◦ exit

//create a communtication program, client and server

//start with the server, upon launch it prints its PID.  =COMPLETE
//The client then takes 2 parameters, the servers PID and a string to send.
//                                                       =COMPLETE

//Client sends the string to the server, then the server prints it without delay.
//                                                       =COMPLETE=
//   -THIS NEEDS TO BE DONE PER STRING, NOT PER CHAR-
//   -My version is working, but I need to impliment a better way-

// serVer needs to recieve strings from several clients in a row without needing to restart.
//                                                       =COMPLETE=

// comms must use exsclusively UNIX signals.
// SIGUSR1 and SIGUSR2 are permitted.                   =COMPLETE=
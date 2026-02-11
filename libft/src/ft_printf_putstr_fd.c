/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: j.fox <jfox.42angouleme@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:35:38 by jfox              #+#    #+#             */
/*   Updated: 2026/02/11 15:04:25 by j.fox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

size_t	ft_printf_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (!s)
	{
		ft_printf_putstr_fd("(null)", fd);
		return (6);
	}
	i = ft_strlen(s);
	write(fd, s, i);
	return (i);
}

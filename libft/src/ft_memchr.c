/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: j.fox <jfox.42angouleme@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:19:11 by jfox              #+#    #+#             */
/*   Updated: 2026/02/11 15:04:25 by j.fox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	chr;
	size_t			i;

	dest = (unsigned char *)s;
	chr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (dest[i] == chr)
			return (&dest[i]);
		i++;
	}
	return (NULL);
}

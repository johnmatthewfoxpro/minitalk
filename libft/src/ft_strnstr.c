/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: j.fox <jfox.42angouleme@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:55:09 by jfox              #+#    #+#             */
/*   Updated: 2026/02/11 15:04:25 by j.fox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	x;

	i = 0;
	if (!*little)
		return ((char *)big);
	if (!*big)
		return (NULL);
	while (big[i] || i < len)
	{
		x = 0;
		while ((big[i + x] == little[x]) && (i + x) < len)
		{
			x++;
			if (little[x] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

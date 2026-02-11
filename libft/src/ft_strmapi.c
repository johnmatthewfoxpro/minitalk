/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: j.fox <jfox.42angouleme@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:57:17 by jfox              #+#    #+#             */
/*   Updated: 2026/02/11 15:04:25 by j.fox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s1;
	size_t	i;
	size_t	len;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	s1 = (char *)ft_calloc((len + 1), (sizeof(char)));
	if (!s1)
		return (NULL);
	while (i < len)
	{
		s1[i] = f(i, s[i]);
		i++;
	}
	return (s1);
}

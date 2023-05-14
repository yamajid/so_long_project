/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:04:29 by yamajid           #+#    #+#             */
/*   Updated: 2023/05/12 14:05:45 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_del_last_char(char *s1, char set)
{
	size_t	len;
	int		i;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	if (s1[len - 1] == '\n')
		s1[len - 1] = '\0';
	return (s1);
}
int	ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned char	*dst;
	unsigned char	*src;
	size_t			i;

	if (n == 0)
		return (0);
	dst = (unsigned char *)s1;
	src = (unsigned char *)s2;
	i = 0;
	while ((dst[i] || src[i]) && i < n)
	{
		if (dst[i] != src[i])
			return (dst[i] - src[i]);
		i++;
	}
	return (0);
}

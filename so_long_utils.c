/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:55:47 by yamajid           #+#    #+#             */
/*   Updated: 2023/05/12 18:23:06 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int	ft_mapsize(t_map *map)
{
	int i;
	i = 0;
	while (map)
	{
		map = map->next;
		i++;
	}
	return (i);
}
t_map	*ft_maplast(t_map *map)
{
	if (map == NULL)
		return (NULL);
	while (map->next != NULL)
		map = map->next;
	return (map);
}
void	ft_mapaddback(t_map **map, t_map *line)
{
	t_map	*lastnode;
	t_map	*tmp;

	tmp = *map;
	if (!map || !line)
		return ;
	if (!*map)
	{
		*map = line;
		return ;
	}
	lastnode = ft_maplast(*map);
	lastnode->next = line;
}

t_map	*ft_newline(char *line, int index)
{
	t_map	*newnode;

	newnode = malloc(sizeof(t_map));
	if (!newnode)
		return (NULL);
	newnode->index = index;
    newnode->line = line;
	newnode->next = NULL;
	return (newnode);
}
int	ft_strchrch(char *s, int c)
{
	int	i;

	if (s == NULL)
		return (1);
	if ((char) c == '\0')
		return (1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}


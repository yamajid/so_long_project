/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:55:47 by yamajid           #+#    #+#             */
/*   Updated: 2023/05/30 15:25:40 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mapsize(t_map *map)
{
	int		i;
	t_map	*tmp;

	i = 0;
	tmp = map;
	while (tmp)
	{
		tmp = tmp->next;
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

	if (!line && !map)
		return ;
	if (!line)
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

char	*ft_del_last_char(char *s1, char set)
{
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	if (s1[len - 1] == '\n')
		s1[len - 1] = '\0';
	return (s1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:56:30 by yamajid           #+#    #+#             */
/*   Updated: 2023/06/01 16:03:36 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_search_for_line(t_map *map, size_t index)
{
	while (map->next != NULL)
	{
		if (map->index == index)
			return (map->line);
		map = map->next;
	}
	return (NULL);
}

int	check_map_valid(t_map *map)
{
	if ((ft_check_lenght(map) == 1 || ft_check_left_and_right(map) == 1)
		|| (ft_check_walls(map) == 1 || ft_check_map_char(map) == 1))
		return (write(1, "Error\n", 7), ft_lstclear(&map), 0);
	if (ft_check_char_count(map, 'P') != 1 || ft_check_char_count(map,
			'E') != 1)
		return (write(1, "Error\n", 7), ft_lstclear(&map), 0);
	if (ft_check_char_count(map, 'C') < 1)
		return (write(1, "Error\n", 7), ft_lstclear(&map), 0);
	return (1);
}

t_map	*ft_get_map(int fd)
{
	char	*line;
	int		index;
	t_map	*map;

	index = 0;
	line = ft_del_last_char(get_next_line(fd), '\n');
	while (line)
	{
		ft_mapaddback(&map, ft_newline(line, index));
		line = ft_del_last_char(get_next_line(fd), '\n');
		index++;
	}
	close(fd);
	return (map);
}

t_player	*ft_get_player_loc(t_map *map)
{
	t_player	*p;
	int			i;
	t_map		*tmp;

	if (map == NULL)
		return (NULL);
	tmp = map;
	while (tmp)
	{
		i = 0;
		while (tmp->line[i])
		{
			if (tmp->line[i] == 'P')
			{
				p = init_player(i, tmp->index, ft_check_char_count(map,
							'C'));
				return (p);
			}
			i++;
		}
		tmp = tmp->next;
	}
	return (NULL);
}

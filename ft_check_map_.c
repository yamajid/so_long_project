/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:48:42 by yamajid           #+#    #+#             */
/*   Updated: 2023/05/11 21:38:05 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_lenght(t_map *map)
{
	size_t	size;
	t_map	*tmp;

	if (map == NULL)
		return (1);
	tmp = map;
	size = ft_strlen(map->line);
	while (tmp)
	{
		if (!tmp->next)
			break ;
		if (size != ft_strlen(tmp->next->line))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
int	ft_check_top_and_buttom_line(t_map *map)
{
	int		i;
	t_map	*last;

	if (map == NULL)
		return (0);
	i = 0;
	while (map->line[i])
	{
		if (map->line[i] != '1')
			return (1);
		i++;
	}
	last = ft_maplast(map);
	i = 0;
	while (last->line[i])
	{
		if (last->line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}
int	ft_check_left_and_right(t_map *map)
{
	int		i;
	t_map	*tmp;
	size_t	size;

	size = ft_strlen(map->line) - 1;
	tmp = map->next;
	i = 0;
	while (tmp)
	{
		if (tmp->next == NULL)
			break ;
		if (tmp->line[0] != '1' || tmp->line[size] != '1')
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
int	ft_check_map_char_count(t_map *map, char c)
{
	t_map	*tmp;
	int		count;
	int		i;

	tmp = map;
	count = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->line[i])
		{
			if (tmp->line[i] == c)
				count++;
			i++;
		}
		tmp = tmp->next;
	}
	return (count);
}
int	ft_check_map_char(t_map *map)
{
	int i;
	t_map *tmp;

	tmp = map;
	i = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->line[i])
		{
			if (tmp->line[i] != 'P' && tmp->line[i] != 'C'
				&& tmp->line[i] != 'E' && tmp->line[i] != '0'
				&& tmp->line[i] != '1')
				return (1);
			i++;
		}
		tmp = tmp->next;
	}
	return (0);
}
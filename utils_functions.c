/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:56:30 by yamajid           #+#    #+#             */
/*   Updated: 2023/05/22 10:24:27 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *ft_search_for_line(t_map *map, int index)
{
    t_map   *tmp;

    tmp = map;
    while (tmp->next != NULL)
    {
        if (tmp->index == index)
            return (tmp->line);
        tmp = tmp->next;
    }
    return (NULL); 
}
int check_map_valid(t_map *map)
{
    if (ft_check_lenght(map) == 1 || ft_check_left_and_right(map) == 1 || 
    (ft_check_top_and_buttom_line(map) == 1) || ft_check_map_char(map) == 1)
        return (write(1, "ERR\n", 4), 0);
    if (ft_check_map_char_count(map, 'P') != 1 || ft_check_map_char_count(map, 'E') != 1)
        return (write(1, "ERR\n", 4), 0);
    if (ft_check_map_char_count(map, 'C') < 1)
        return (write(1, "ERR\n", 4), 0);
    return (1);
}

t_map   *ft_get_map(int fd)
{
    char   *line;
    int     index;
    t_map   *map;

    index = 0;
    line = ft_del_last_char(get_next_line(fd), '\n');
    while (line)
    {
        ft_mapaddback(&map, ft_newline(line, index));
        line = ft_del_last_char(get_next_line(fd), '\n');
        index ++;
    }
    return (map);
}

t_player    *ft_get_player_loc(t_map *map)
{
    t_player    *p;
    int         i;
    t_map       *tmp;

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
                p = init_player(tmp, i, tmp->index, ft_check_map_char_count(map, 'C'));
                return (p);
            }
            i++;
        }
        tmp = tmp->next;
    }
    return (NULL);
}

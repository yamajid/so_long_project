/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:22:38 by yamajid           #+#    #+#             */
/*   Updated: 2023/05/27 16:32:16 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_flood_fill(t_map *map2, int x, int y)
{
    char        *line;

    line = ft_search_for_line(map2, y);
    if (line == NULL)
        return ;
    if (line[x] == 'W' || line[x] == '1')
        return ;
    if (x < 0 || x >= ft_strlen(line)) 
        return ;
    if (y < 0 || y >= ft_mapsize(map2))
        return ;
    line[x] = 'W';
    ft_flood_fill(map2, x + 1, y);
    ft_flood_fill(map2, x - 1, y);
    ft_flood_fill(map2, x, y + 1);
    ft_flood_fill(map2, x, y - 1);
    return ;
}
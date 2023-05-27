/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:15:10 by yamajid           #+#    #+#             */
/*   Updated: 2023/05/27 13:52:50 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void player_exit(t_map *map, t_player *p)
{
    t_map       *tmp;
    int         i;

    if (map == NULL || p == NULL)
        return ;
    tmp = map;
    while (tmp)
    {
        i = 0;
        while (tmp->line[i])
        {
            if (tmp->line[i] == 'E')
            {
                p->exit_x = i;
                p->exit_y = tmp->index;
            }
            i++;
        }
        tmp = tmp->next;
    }
    return ;
}

t_player    *init_player(t_map *m, int x, int y, int coins_count)
{
    t_player    *p;

    p = (t_player *)malloc(sizeof(t_player));
    if (!p)
        return (NULL);
    p->coins = 0;
    p->coins_count = coins_count;
    p->x = x;
    p->y = y;
    // player_exit(m, p);
    return (p);
}

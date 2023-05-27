/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:02:34 by yamajid           #+#    #+#             */
/*   Updated: 2023/05/27 14:03:38 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_draw_map(t_map *map)
{
    t_map   *tmp;
    t_game  *game;
    int     index;
    int     y;
    t_tiles *t;
    
    tmp = map;
    game = map->game;
    t = map->tiles;
    while (tmp)
    {
        index = 0;
        while (tmp->line[index])
        {
            if (tmp->line[index] == '0')
                mlx_put_image_to_window(game->mlx, game->window, t->space, index * 50, tmp->index * 50);
            else if (tmp->line[index] == '1')
                mlx_put_image_to_window(game->mlx, game->window, t->w, index * 50, tmp->index * 50);
            else if (map->line[index] == 'E')
                    mlx_put_image_to_window(game->mlx, game->window, t->e, index * 50, tmp->index * 50);
            else if (tmp->line[index] == 'P')
                mlx_put_image_to_window(game->mlx, game->window, t->p, index * 50, tmp->index * 50);
            else if (tmp->line[index] == 'C')
                mlx_put_image_to_window(game->mlx, game->window, t->c, index * 50, tmp->index * 50);
            index++;
        }
        tmp = tmp->next;
    }
}
void    first_drawing(t_map *map, t_game *game)
{
    t_tiles     *t;
    t_map       *tmp;
    int         index;
    int         y;

    tmp = map;
    t = map->tiles;
    while (map)
    {
        y = map->index * 50;
        index = 0;
        while (map->line[index])
        {
            if (map->line[index] == '0')
                mlx_put_image_to_window(game->mlx, game->window, t->space, index * 50, y);
            else if (map->line[index] == '1')
                mlx_put_image_to_window(game->mlx, game->window, t->w, index * 50, y);
            else if (map->line[index] == 'E')
                mlx_put_image_to_window(game->mlx, game->window, t->e, index * 50, y);
            else if (map->line[index] == 'P')
                mlx_put_image_to_window(game->mlx, game->window, t->p, index * 50, y);
            else if (map->line[index] == 'C')
                mlx_put_image_to_window(game->mlx, game->window, t->c, index * 50, y);
            index++;
        }
        map = map->next;
    }
}

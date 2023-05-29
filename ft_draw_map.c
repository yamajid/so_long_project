/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:02:34 by yamajid           #+#    #+#             */
/*   Updated: 2023/05/29 21:22:45 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	help_draw_func(t_game *game, t_tiles *t, t_map *map, int index)
{
	while (map)
	{
		index = 0;
		while (map->line[index])
		{
			if (map->line[index] == '0')
				mlx_put_image_to_window(game->mlx, game->win, t->space, index
					* 50, map->index * 50);
			else if (map->line[index] == '1')
				mlx_put_image_to_window(game->mlx, game->win, t->w, index * 50,
					map->index * 50);
			else if (map->line[index] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, t->e, index * 50,
					map->index * 50);
			else if (map->line[index] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, t->p, index * 50,
					map->index * 50);
			else if (map->line[index] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, t->c, index * 50,
					map->index * 50);
			index++;
		}
		map = map->next;
	}
}

void	ft_draw_map(t_map *m)
{
	t_game	*game;
	int		index;
	t_tiles	*t;

	game = m->game;
	t = m->tiles;
	index = 0;
	help_draw_func(game, t, m, index);
}

void	first_drawing(t_map *map, t_game *game)
{
	int		index;
	t_tiles	*t;

	t = map->tiles;
	index = 0;
	help_draw_func(game, t, map, index);
}

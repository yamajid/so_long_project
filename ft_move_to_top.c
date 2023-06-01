/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_to_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:53:29 by yamajid           #+#    #+#             */
/*   Updated: 2023/06/01 16:20:08 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	help_top_move_function(char *line, t_player *player, t_map *map)
{
	int	i;

	i = player->x;
	if (line[i] == 'C')
	{
		line[i] = 'P';
		line = ft_search_for_line(map, player->y);
		line[i] = '0';
		map->player->coins++;
		mlx_clear_window(map->game->mlx, map->game->win);
		ft_draw_map(map);
	}
	else if (line[i] == '0')
	{
		line[i] = 'P';
		line = ft_search_for_line(map, player->y);
		line[i] = '0';
		mlx_clear_window(map->game->mlx, map->game->win);
		ft_draw_map(map);
	}
}

int	ft_top_move(t_map *map)
{
	t_move	move;

	move.player = ft_get_player_loc(map);
	move.line = ft_search_for_line(map, move.player->y - 1);
	if (move.line == NULL)
		return (free(move.player), 0);
	move.i = move.player->x;
	if (move.line[move.i] == '1')
		return (free(move.player), 0);
	if (move.line[move.i] == 'C' || move.line[move.i] == '0')
		help_top_move_function(move.line, move.player, map);
	if (move.line[move.i] == 'E')
	{
		if (move.player->coins == move.player->coins_count)
			return (free(move.player), ft_win(map), 0);
		else
			return (free(move.player), 0);
	}
	ft_putnbr(map->player->moves++);
	write(1, "\n", 1);
	return (free(move.player), 0);
}

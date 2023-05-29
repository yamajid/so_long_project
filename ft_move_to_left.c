/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_to_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 23:55:22 by yamajid           #+#    #+#             */
/*   Updated: 2023/05/29 19:07:17 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	help_left_move_function(char *line, t_player *player, t_map *map)
{
	int	i;

	i = player->x;
	if (line[i - 1] == 'C')
	{
		line[i - 1] = 'P';
		line[i] = '0';
		map->player->coins++;
		mlx_clear_window(map->game->mlx, map->game->win);
		ft_draw_map(map);
	}
	else if (line[i - 1] == '0')
	{
		line[i - 1] = 'P';
		line[i] = '0';
		mlx_clear_window(map->game->mlx, map->game->win);
		ft_draw_map(map);
	}
}

void	ft_left_move(t_map *map)
{
	t_move	move;

	move.player = ft_get_player_loc(map);
	move.line = ft_search_for_line(map, move.player->y);
	if (move.line == NULL)
		return ;
	move.i = move.player->x;
	if (move.line[move.i - 1] == '1')
		return ;
	else if (move.line[move.i - 1] == 'C' || move.line[move.i - 1] == '0')
		help_left_move_function(move.line, move.player, map);
	if (move.line[move.i - 1] == 'E'
		&& move.player->coins == move.player->coins_count)
	{
		write(1, "You Win\n", 7);
		mlx_clear_window(map->game->mlx, map->game->win);
		exit(1);
	}
	else
	{
		ft_putnbr(map->player->moves++);
		write(1, "\n", 1);
		return ;
	}
}
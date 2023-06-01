/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:26:23 by yamajid           #+#    #+#             */
/*   Updated: 2023/06/01 16:44:38 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_map *map)
{
	write(1, "GAME OVER\n", 11);
	destroy_images(map);
	mlx_destroy_window(map->game->mlx, map->game->win);
	ft_lstclear(&map);
	exit(1);
	return (0);
}

void	destroy_images(t_map *map)
{
	if (map->tiles->p)
		mlx_destroy_image(map->game->mlx, map->tiles->p);
	if (map->tiles->e)
		mlx_destroy_image(map->game->mlx, map->tiles->e);
	if (map->tiles->space)
		mlx_destroy_image(map->game->mlx, map->tiles->space);
	if (map->tiles->w)
		mlx_destroy_image(map->game->mlx, map->tiles->w);
	if (map->tiles->c)
		mlx_destroy_image(map->game->mlx, map->tiles->c);
	free(map->tiles);
	map->tiles = NULL;
}

int	fun(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		write(1, "GAME OVER\n", 11);
		destroy_images(map);
		mlx_destroy_window(map->game->mlx, map->game->win);
		free(map->game);
		ft_lstclear(&map);
		exit(1);
	}
	else if (keycode == 13 || keycode == 126)
		ft_top_move(map);
	else if (keycode == 0 || keycode == 123)
		ft_left_move(map);
	else if (keycode == 2 || keycode == 124)
		ft_right_move(map);
	else if (keycode == 1 || keycode == 125)
		ft_buttom_move(map);
	return (0);
}

void	key_hook(t_map *map)
{
	if (map == NULL)
		return ;
	mlx_key_hook(map->game->win, &fun, map);
	mlx_hook(map->game->win, 17, 0, ft_exit, map);
}

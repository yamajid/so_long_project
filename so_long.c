/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:26:55 by yamajid           #+#    #+#             */
/*   Updated: 2023/05/29 21:41:44 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*mapcopy(t_map *map)
{
	t_map	*map2;

	map2 = NULL;
	while (map != NULL)
	{
		ft_mapaddback(&map2, ft_newline(ft_strdup(map->line), map->index));
		map = map->next;
	}
	return (map2);
}

t_tiles	*load_tiles(void *mlx)
{
	t_tiles	*t;
	int		i;
	int		j;

	t = (t_tiles *)malloc(sizeof(t_tiles));
	t->e = mlx_xpm_file_to_image(mlx, "src/e.xpm", &i, &j);
	t->c = mlx_xpm_file_to_image(mlx, "src/c.xpm", &i, &j);
	t->p = mlx_xpm_file_to_image(mlx, "src/p.xpm", &i, &j);
	t->w = mlx_xpm_file_to_image(mlx, "src/w.xpm", &i, &j);
	t->space = mlx_xpm_file_to_image(mlx, "src/sp.xpm", &i, &j);
	return (t);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	(void) argc;
	vars.map = (t_map *)malloc(sizeof(t_map));
	vars.game = (t_game *)malloc(sizeof(t_game));
	vars.t = (t_tiles *)malloc(sizeof(t_tiles));
	vars.fd = open(argv[1], O_RDONLY);
	if (vars.fd < 0)
		return (0);
	vars.map = ft_get_map(vars.fd);
	ft_help_main(&vars.map, &vars.player, &vars.game);
	vars.game->win = mlx_new_window(vars.game->mlx, ft_strlen(vars.map->line)
			* 50, ft_mapsize(vars.map) * 50, "so_long");
	if (!vars.game->win)
		return (write(1, "Error Creating window\n", 23), 0);
	vars.t = load_tiles(vars.game->mlx);
	free(vars.map2);
	vars.map->game = vars.game;
	vars.map->player = vars.player;
	vars.map->tiles = vars.t;
	first_drawing(vars.map, vars.game);
	key_hook(vars.game, vars.t, vars.map);
	mlx_loop(vars.game->mlx);
	return (0);
}

void	ft_help_main(t_map **map, t_player **player, t_game **game)
{
	t_map	*map2;

	if (check_map_valid(*map) == 0)
	{
		write(1, "ERR\n", 4);
		exit(1);
	}
	map2 = mapcopy(*map);
	(*player) = ft_get_player_loc(map2);
	(*player)->moves = 1;
	ft_flood_fill(map2, (*player)->x, (*player)->y);
	if (ft_check_char_count(map2, 'C') != 0)
	{
		write(1, "ERR\n", 4);
		exit(1);
	}
	(*game)->mlx = mlx_init();
	if (!(*game)->mlx)
	{
		write(1, "Error initializing Minilibx\n", 29);
		exit(1);
	}
}

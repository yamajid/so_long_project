/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:26:55 by yamajid           #+#    #+#             */
/*   Updated: 2023/06/01 16:51:21 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_lstclear(t_map **lst)
{
	t_map	*tmp;

	if (!lst || !(*lst))
		return ;
	tmp = *lst;
	while (*lst)
	{
		*lst = (*lst)->next;
		free(tmp->line);
		free(tmp);
		tmp = *lst;
	}
}

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
	if (!t)
		return (NULL);
	t->e = mlx_xpm_file_to_image(mlx, "src/e.xpm", &i, &j);
	if (!t->e)
		return (write(1, "Error\n", 7), exit(1), NULL);
	t->c = mlx_xpm_file_to_image(mlx, "src/c.xpm", &i, &j);
	if (!t->c)
		return (write(1, "Error\n", 7), exit(1), NULL);
	t->p = mlx_xpm_file_to_image(mlx, "src/p.xpm", &i, &j);
	if (!t->p)
		return (write(1, "Error\n", 7), exit(1), NULL);
	t->w = mlx_xpm_file_to_image(mlx, "src/w.xpm", &i, &j);
	if (!t->w)
		return (write(1, "Error\n", 7), exit(1), NULL);
	t->space = mlx_xpm_file_to_image(mlx, "src/sp.xpm", &i, &j);
	if (!t->space)
		return (write(1, "Error\n", 7), exit(1), NULL);
	return (t);
}

void	ft_help_main(t_map **map, t_player **player, t_game **game,
		t_tiles **tiles)
{
	t_map	*map2;

	if (map == NULL)
		return ;
	if (check_map_valid(*map) == 0)
		exit(1);
	map2 = mapcopy(*map);
	(*player) = ft_get_player_loc(map2);
	(*player)->moves = 1;
	ft_flood_fill(map2, (*player)->x, (*player)->y);
	if (ft_check_char_count(map2, 'C') != 0)
	{
		ft_lstclear(&map2);
		ft_error(*map);
	}
	ft_lstclear(&map2);
	(*game)->mlx = mlx_init();
	if (!(*game)->mlx)
		ft_error(*map);
	(*game)->win = mlx_new_window((*game)->mlx, ft_strlen((*map)->line) * 50,
			ft_mapsize(*map) * 50, "so_long");
	if (!(*game)->win)
		ft_error(*map);
	(*tiles) = load_tiles((*game)->mlx);
}

void	b(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	atexit(b);
	if (argc != 2)
	{
		write(1, "Error\n", 7);
		return (0);
	}
	vars.game = (t_game *)malloc(sizeof(t_game));
	if (!vars.game)
		return (0);
	vars.fd = open(argv[1], O_RDONLY);
	if (vars.fd < 0)
		return (0);
	vars.map = ft_get_map(vars.fd);
	if (vars.map == NULL)
	{
		write(1, "Error\n", 7);
		free(vars.game);
		return (0);
	}
	ft_help_main(&vars.map, &vars.player, &vars.game, &vars.t);
	vars.map->game = vars.game;
	vars.map->player = vars.player;
	vars.map->tiles = vars.t;
	first_drawing(vars.map);
	key_hook(vars.map);
	mlx_loop(vars.game->mlx);
	return (0);
}

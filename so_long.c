/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:26:55 by yamajid           #+#    #+#             */
/*   Updated: 2023/05/27 16:31:00 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map *mapcopy(t_map *map)
{
    t_map   *map2;
    
    map2 = NULL;
    while (map != NULL)
    {
        ft_mapaddback(&map2, ft_newline(ft_strdup(map->line), map->index));
        map = map->next;
    }
    return (map2);
}
t_map *mapcopy2(t_map *map)
{
    t_map   *map2;
    
    map2 = NULL;
    while (map != NULL)
    {
        ft_mapaddback(&map2, ft_newline(ft_strdup(map->line), map->index));
        map = map->next;
    }
    return (map2);
}

t_tiles *load_tiles(void *mlx)
{
    t_tiles *t;
    int i;
    int j;

    t = (t_tiles *)malloc(sizeof(t_tiles));
    t->c = mlx_xpm_file_to_image(mlx, "src/c.xpm", &i, &j);
    t->e = mlx_xpm_file_to_image(mlx, "src/e.xpm", &i, &j);
    t->p = mlx_xpm_file_to_image(mlx, "src/p.xpm", &i, &j);
    t->space = mlx_xpm_file_to_image(mlx, "src/sp.xpm", &i, &j);
    t->w = mlx_xpm_file_to_image(mlx, "src/w.xpm", &i, &j);
    return (t);
}

int main (int argc, char **argv)
{
    t_player    *player;
    t_game      *game;
    t_map   *map;
    t_map   *map2;
    t_map   *tmp;
    int     fd;
    int     index;
    void    *mlx;
    int     y;
    t_tiles *t;
    
    map = (t_map *)malloc(sizeof(t_map));
    game = (t_game *)malloc(sizeof(t_game));
    t = (t_tiles *)malloc(sizeof(t_tiles));
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return (0);
    map = ft_get_map(fd);
    if (check_map_valid(map) == 0)
        return (write(1, "ERR\n", 4), 0);
    map2 = mapcopy(map);
    map->map3 = mapcopy2(map);
    player = ft_get_player_loc(map2);
    ft_flood_fill(map2, player->x, player->y);
    if (ft_check_map_char_count(map2, 'C') != 0 || ft_check_map_char_count(map2, 'E') != 0)
        return (0);
    game->mlx = mlx_init();
    if (!game->mlx)
        return (write(1, "Error initializing Minilibx\n", 29), 0);
    game->window = mlx_new_window(game->mlx,ft_strlen(map->line) * 50, ft_mapsize(map) * 50,"so_long");
    if (!game->window)
        return (write(1, "Error Creating window\n", 23), 0);
    t = load_tiles(game->mlx);
    free (map2);
    map->game = game;
    map->tiles = t;
    map->player = player;
    first_drawing(map, game);
    key_hook(game, t, map);
    mlx_loop(game->mlx);
    return (0);
    
}

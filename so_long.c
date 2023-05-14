/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:26:55 by yamajid           #+#    #+#             */
/*   Updated: 2023/05/14 13:51:21 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "stdio.h"
void    ft_get_map(t_map *map, int fd)
{
    char   *line;
    int     index;

    index = 0;
    line = ft_del_last_char(get_next_line(fd), '\n');
    while (line)
    {
        ft_mapaddback(&map, ft_newline(line, index));
        line = ft_del_last_char(get_next_line(fd), '\n');
        index ++;
    }
    if (ft_check_lenght(map) == 1 || ft_check_left_and_right(map) == 1 || 
    (ft_check_top_and_buttom_line(map) == 1) || ft_check_map_char(map) == 1)
    {
        printf("here1");
        return ;
    }
    if (ft_check_map_char_count(map, 'P') != 1 || ft_check_map_char_count(map, 'E') != 1)
    {
        printf("here2");
        return ;
    }
    if (ft_check_map_char_count(map, 'C') < 1)
    {
        printf("here3");
        return ;
    }
    
}

int main (int argc, char **argv)
{
    t_map   *map;
    t_map   *map2;
    int     fd;
    char    *line;
    int     len;
    int     index;
    
    map = NULL;
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return (0);
    ft_get_map(map, fd);
    map2 = map;
}

// char *ft_get_player_loc(t_map *map)
// {
//     t_map *tmp;
//     char *str;
//     int i;
    
//     if (map == NULL)
//         return (NULL);
//     tmp = map;
//     while (tmp)
//     {
//         i = 0;
//                 str[0] = i;
//                 str[1] = tmp->index;
//         while (tmp->line[i])
//         {
//             if (tmp->line[i] == 'P')
//             {
//                 ft_check_for_valid_map(map, str);
//             }
//             i++;
//         }
//         tmp = tmp->next;
//     }
//     return (NULL);
    
// }

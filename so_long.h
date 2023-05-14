/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:26:53 by yamajid           #+#    #+#             */
/*   Updated: 2023/05/14 13:14:27 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
# define SO_LONG_H

#include"mlx.h"
#include "stdlib.h"
#include "unistd.h"
#include "fcntl.h"
#include "gnl/get_next_line.h"

typedef struct map
{
    char    *line;
    size_t     index;
    struct map *next;
}       t_map;

// typedef struct palyer
// {
//     size_t x;
//     int y;
//     int coins;
//     int coins_count;
// }   t_player;

void    ft_check_top_or_buttom(t_map *map, size_t x, size_t y, int i);
char	*ft_substr(char *str, unsigned int start, size_t len);
int     ft_check_for_valid_map(t_map  *map, char *str);
int     ft_check_map_char_count(t_map *map, char c);
int     ft_check_top_and_buttom_line(t_map *map);
int     ft_check_top_and_buttom_line(t_map *map);
void	ft_mapaddback(t_map **map, t_map *line);
char	*ft_strjoin(char *str1, char *str2);
int     ft_check_left_and_right(t_map *map);
t_map	*ft_newline(char *line, int index);
char	*ft_del_last_char(char *s1, char set);
void    ft_get_map(t_map *map, int fd);
int     ft_check_map_char(t_map *map);
int     ft_strchrch(char *s, int c);
int     ft_check_lenght(t_map *map);
t_map	*ft_maplast(t_map *stack);
int	    ft_mapsize(t_map *map);
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *s1);


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# endif
